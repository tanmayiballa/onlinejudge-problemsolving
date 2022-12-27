#include<iostream>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;
#define Inf 10000005.0

vector<pair<double,double>> xy;

double euclid(int i,int j){
  return sqrt(pow((xy[j].second - xy[i].second),2) + pow((xy[j].first - xy[i].first),2));
}

double MST(){
  int n = xy.size();
  vector<bool> vis(n,0);
  vector<double> distance(n,Inf);

  int start = 0;
  distance[start] = 0;

  while(1){

    vis[start] = 1;
    
    for(int i=0;i<n;i++){
    if(!vis[i]){
      double dist = euclid(i,start);
      if(dist<distance[i]) distance[i] = dist;
    }
    }
    
    int min_dist = Inf;
    int next_min = -1;
    
    for(int i=0;i<n;i++){
    if(!vis[i] && distance[i]<min_dist){
      min_dist = distance[i];
      next_min = i;
    }
    }
    start = next_min;
    if(next_min == -1) break;
  }
  double min_distance = 0.0;
  for(int i=0;i<distance.size();i++) min_distance+=distance[i];
  return min_distance;
}

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    double a,b;
    xy.clear();
    pair<double,double> p;
    for(int i=0;i<n;i++){
      cin>>a>>b;
      p.first = a;
      p.second = b;
      xy.push_back(p);
    }
    cout<<fixed<<setprecision(2);
    double d = MST();
    cout << d <<"\n";
    if(t) cout<<"\n";
  }
}