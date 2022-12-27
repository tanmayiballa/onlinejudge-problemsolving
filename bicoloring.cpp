#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int adj_list[201][201];
int color_arr[201];

void init_matrix(int n){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++) adj_list[i][j]  = 0;
    color_arr[i] = -1;
  }
  return;
}

bool check_bicolor(int index, int n, bool color){

  //cout<<index<<color<<"\n";

  if(index == n) return 1;

  for(int i=0;i<n;i++){
    if(index==i) continue;
    if(adj_list[index][i] == 1 && color_arr[i] == color) return 0;
  }
  color_arr[index] = color;

  if(check_bicolor(index+1, n, color) || check_bicolor(index+1,n,!color)) return 1;
  else return 0;
}

int main(){
  int n,a,b;
  while(cin>>n){
    if(n==0) break;
    int edges;
    cin>>edges;
    init_matrix(n);
    for(int i=0;i<edges;i++){
      cin>>a>>b;
      adj_list[a][b] = adj_list[b][a] = 1;
    }

    if(check_bicolor(0,n,0)) cout<<"BICOLORABLE."<<"\n";
    else cout<<"NOT BICOLORABLE."<<"\n";
  }
}