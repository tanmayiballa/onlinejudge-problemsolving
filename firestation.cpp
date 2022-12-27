#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#define Inf 10000007

vector<bool> firestation;
int adj[501][501];

void initialize(int n){
  firestation.clear();
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      adj[i][j] = Inf;
      if(i==j) adj[i][j] = 0;
    }
    firestation.push_back(0);
  }
  return;
}

int check_distance(int n){
  int dist = 0;
  for(int i=0;i<n;i++){
    int min_dist = 10000007;
    for(int j=0;j<n;j++){
      if((firestation[j]==1) && adj[i][j]<min_dist) min_dist = adj[i][j];
    }
    //cout<<i<<" "<<min_dist<<"\n";
    if(min_dist>dist) dist = min_dist;
  }
  return dist;
}

void print_adj(int n){
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cout<<i<<" "<<j<<" "<<adj[i][j]<<"\n";
  return;
}

int Floyd(int n){
  for(int k=0;k<n;k++) //intermediate nodes
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        if(adj[i][j]>adj[i][k] + adj[k][j] && adj[i][k]!=Inf && adj[k][j]!=Inf && i!=j) adj[i][j] = adj[i][k] + adj[k][j];

  //print_adj(n);

  int min_distance = 10000007;
  int ind = -1;
  //for(int i=0;i<firestation.size();i++) cout<<firestation[i]<<" ";
  //cout<<"gf/n";
  for(int i=0;i<n;i++){
    if(firestation[i]) continue;
    //cout<<"Hi";
    firestation[i] = 1;
    int dist = check_distance(n);
    //cout<<i<<" "<<dist<<"\n";
    if(dist<min_distance){
      min_distance = dist;
      ind = i;
    }
    firestation[i] = 0;
  }
  //cout<<"Index is:"<<ind<<"\n";
  if(ind==-1) ind=0;
  return ind+1;
}

int main(){
  int t;
  cin>>t;
  while(t--){
    int f,n,k;
    cin>>f>>n;
    //cout<<f<<" "<<n<<"\n";
    initialize(n);
    for(int i=0;i<f;i++) {
      cin>>k;
      //cout<<k<<"\n";
      firestation[k-1] = 1;
    }
    int a,b,c;
    string s;
    getline(cin,s);
    while(getline(cin,s)){
      //cout<<"Hi"<<t;
      //cout<<s<<"\n";
      if(s.empty()) break;
      stringstream ss(s);
      //if(s == "") break;
       ss>>a;
       ss>>b;
       ss>>c;
      adj[a-1][b-1] = c;
      adj[b-1][a-1] = c;
    }
    //print_adj(n);
    cout<<Floyd(n)<<"\n";
    if(t) cout<<"\n";
  }
}