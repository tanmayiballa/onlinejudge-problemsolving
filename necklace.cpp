#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int V;
int beads[51][51];
int odd_ind;
vector<pair<int,int>> path;

void initialize(){
  path.clear();
  for(int i=0;i<50;i++)
    for(int j=0;j<50;j++)
      beads[i][j] = 0;
  return;
}

void eulerian_cycle(int ind){
  for(int i=0;i<V;i++){
    if(beads[ind][i]!=0){
      beads[ind][i]--;
      beads[i][ind]--;

      eulerian_cycle(i);

      pair<int,int> p;
      p.first = ind;
      p.second = i;
      path.push_back(p);
    }
  }
}


int check_eulerian(){
  int odd_cnt = 0;
  for(int i=0;i<V;i++){
    int cnt = 0;
    for(int j=0;j<V;j++) cnt+=beads[i][j];
    //cout<<i<<" "<<cnt<<"\n";
    if(cnt%2 != 0){
      odd_cnt++;
      odd_ind = i;
    }
  }
  //cout<<odd_cnt<<"\n";
  return odd_cnt;
}

void print_beads(){
  for(int i=0;i<V;i++)
    {for(int j=0;j<V;j++) cout<<beads[i][j]<<" ";cout<<"\n";}
  return;
}
int main(){
  int t;
  cin>>t;
  int cases = 0;
  while(t--){
    cases++;
    int edges,a,b;
    cin>>edges;
    initialize();
    V = 0;
    for(int i=0;i<edges;i++){
      cin>>a>>b;
      beads[a-1][b-1]++;
      beads[b-1][a-1]++;
      if(a>V) V = a;
      if(b>V) V = b;
    }
     //print_beads();
    cout<<"Case #"<<cases<<"\n";

    int odd_deg = check_eulerian();
    //cout<<odd_deg<<"\n";
    if(odd_deg!=0){
      cout<<"some beads may be lost"<<"\n";
      if(t) cout<<"\n";
      continue;
    }
    odd_ind = V-1;
    eulerian_cycle(odd_ind);
    //cout<<path.size()<<"\n";
    if(path.size() != edges){
      cout<<"some beads may be lost"<<"\n";
      if(t) cout<<"\n";
      continue;
    }
    for(int i=0;i<path.size();i++){
      cout<<path[i].second+1<<" "<<path[i].first+1<<"\n";
      //if(i!=path.size()-1) cout<<"\n";
    }
    if(t) cout<<"\n";
  }
}
