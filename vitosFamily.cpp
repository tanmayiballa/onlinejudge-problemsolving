#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
  int t;
  cin>>t;

  while(t--){
    int n,k;
    cin>>n;

    vector<int> streets;

    for(int i=0;i<n;i++){
      cin>>k;
      streets.push_back(k);
    }

    sort(streets.begin(), streets.end());

    int sum = 0;
    int dp[n+1];

    for(int i=0;i<n;i++) sum+=(streets[i] - streets[0]);

    dp[0] = sum;

    int min_val = dp[0];
    int min_street = 0;

    for(int i=1;i<n;i++){
      dp[i] = dp[i-1] - (n-i-1)*(streets[i] - streets[i-1]) + (i-1)*(streets[i] - streets[i-1]);
      if(dp[i]<min_val){
        min_val = dp[i];
      }
    }
    cout<<min_val<<"\n";
    //if(t) cout<<"/n";
  }
}
