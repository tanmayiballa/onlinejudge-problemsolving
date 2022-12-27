#include<iostream>
#include<bits/stdc++.h>

using namespace std;

string dp[1001];

string add_strings(string a, string b){
    int m = a.length();
    int n = b.length();
    string res_str = "";
    
    int i,j;
    i = m-1;
    j = n-1;
    int carry = 0;
    
    while(j>=0 && i>=0){
    int num1 = a[i] - '0';
    int num2 = b[j] - '0';
    int res = num1 + num2 + carry;
    string unit = to_string(res%10);
    carry = res/10;
    res_str+=unit;
    j--;
    i--;
    }
    
    while(j>=0){
    int num = b[j] - '0';
    int res = num + carry;
    string unit = to_string(res%10);
    carry = res/10;
    res_str+=unit;
    j--;
    }
    
    while(i>=0){
    int num = a[i] - '0';
    int res = num + carry;
    string unit = to_string(res%10);
    carry = res/10;
    res_str+=unit;
    i--;
    }
    
    if(carry!=0) res_str+=to_string(carry);
    
    string new_str = "";
    
    for(int i = res_str.length()-1;i>=0;i--) new_str+=res_str[i];
    //cout<<new_str<<"\n";
    return new_str;
}

void counting(){
  bool i_1,i_2,i_3;
  
  i_1 = 0;
  i_2 = 0;
  i_3 = 0;
  
  dp[0] = "1";
  dp[1] = "2";
  dp[2] = "5";

  for(int i=3;i<=1000;i++){
    i_1 = (i>=1)?1:0;
    i_2 = (i>=2)?1:0;
    i_3 = (i>=3)?1:0;
    dp[i] = "";
    //dp[i] = 2*dp[i-1]*i_1 + dp[i-2]*i_2 + dp[i-3]*i_3;

    if(i_1) dp[i]+=add_strings(dp[i-1],dp[i-1]);
    if(i_2) dp[i] = add_strings(dp[i],dp[i-2]);
    if(i_3) dp[i] = add_strings(dp[i], dp[i-3]);
  }
  return;
}

int main(){
  int sum;
  counting();
  while(cin>>sum){
     cout<<dp[sum]<<"\n";
  }
}