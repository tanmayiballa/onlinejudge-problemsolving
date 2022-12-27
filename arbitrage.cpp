#include<iostream>
#include<bits/stdc++.h>

using namespace std;

double dp[30][30][30];
int parent[30][30][30];

void initialize(int n){
  for(int i=0;i<=n;i++){
    for(int j=0;j<=n;j++){
      for(int k=0;k<=n;k++){
        dp[i][j][k] = 0;
        parent[i][j][k] = 0;
      }
    }
  }
  return;
}

void check_profit(int n){
  for(int move = 1;move<=n;move++){
    for(int mid = 0;mid<n;mid++){
      for(int begin = 0;begin<n;begin++){
        for(int end = 0;end<n;end++){
          if(dp[begin][end][move]<dp[begin][mid][move-1]*dp[mid][end][1]){
            dp[begin][end][move] = dp[begin][mid][move-1]*dp[mid][end][1];
            parent[begin][end][move] = mid; 
          }
        }
      }
    }

    // Check for profit.

    for (int i = 0; i < n; i++)
        {
            if (dp[i][i][move] > 1.01)
            {
                vector<int> path;
                int j = i;
                while (move-1>0){
                 j = parent[i][j][move];
                 move--;
                 path.push_back(j); 
                }
                path.push_back(i);
           
                for(int k=path.size()-1;k>=0;k--) cout<<path[k]+1<<" ";
                cout<<i+1<<"\n";
                return;
            }
        }
    
  }
  cout<<"no arbitrage sequence exists"<<"\n";
  return;
  
}

int main(){
  int n;
  while(cin>>n){
    initialize(n);
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(i==j) dp[i][j][1] = 1.0;
        else cin>>dp[i][j][1];
        parent[i][j][1] = i;
      }
    }
    check_profit(n);
  }
}