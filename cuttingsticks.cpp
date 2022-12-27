#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int sticks[55];
int dp[55][55];
int Inf = 10000007;

void initialize(int n){
  for(int i=0;i<55;i++){
    for(int j=0;j<55;j++)  dp[i][j] = -1;
    sticks[i] = 0;
  }
  return;
}

int min_cuts(int l, int r){
  //cout<<l<<" "<<r<<"\n";
  if(r == l+1) return 0;
  //cout<<l<<" "<<r<<"\n";

  if(dp[l][r]!=-1) return dp[l][r];
  //cout<<l<<" "<<r<<"\n";

  int min_val = Inf;

  for(int i=l+1;i<r;i++){
    //cout<<"hi";
    int k = min_cuts(l,i) + min_cuts(i,r) + (sticks[r] - sticks[l]);
    if(k<min_val) min_val = k;
  }

  dp[l][r] = min_val;

  return min_val;
}

int main(){
  int n,i,j;
  while(1){
    cin>>n;
    if(n==0) break;
    int k;
    cin>>k;
    initialize(k);
    
    for(i=0;i<k;i++) cin>>sticks[i+1];

    sticks[k+1] = n;
    k+=1;
    cout<<"The minimum cutting is "<<min_cuts(0,k)<<".\n";
  }
}