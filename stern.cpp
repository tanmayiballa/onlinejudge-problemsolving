#include<iostream>
#include<bits/stdc++.h>

using namespace std;


string stern_ns(int n, int m, string s){
  pair<int,int> left;
  pair<int,int> right;
  pair<int,int> curr;

  left.first = 0;
  left.second = 1;
  right.first = 1;
  right.second = 0;
  curr.first = 1;
  curr.second = 1;

  float req_frac = n/m;
  string res = "";

  while(curr.first!=n || curr.second!=m){
    int ad = n*curr.second;
    int cb = m*curr.first;
    if(ad<cb){
      res+='L';
      right.first = curr.first;
      right.second = curr.second;
    }
    else{
      res+='R';
      left.first = curr.first;
      left.second = curr.second;
    }
    curr.first = left.first + right.first;
    curr.second = left.second + right.second;
  }
  return res;
}

int main(){
  int n,m,t_n,t_m;
  while(cin>>n>>m){
    if(n==1 && m==1) break;
    cout<<stern_ns(n,m,"")<<"\n";
  }
}