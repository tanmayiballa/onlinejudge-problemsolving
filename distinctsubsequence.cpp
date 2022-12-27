#include<iostream>
#include<bits/stdc++.h>

using namespace std;

string string_add(string a, string b){
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

int main(){
  int t;
  cin>>t;
  while(t--){
    string s,p;
    cin>>s>>p;
    //cout<<s<<" "<<p<<"\n";
    int s_l = s.length();
    int p_l = p.length();

    string dp[s_l+2][p_l+2];
    for(int i=0;i<=s_l;i++) for(int j=0;j<=p_l;j++) dp[i][j] = '0';

    for(int i=0;i<=s_l;i++) dp[i][0] = '1';

    for(int i=1;i<=s_l;i++){
      for(int j=1;j<=p_l;j++){
        if(s[i-1]==p[j-1]) dp[i][j] = string_add(dp[i-1][j],dp[i-1][j-1]);
        else dp[i][j] = dp[i-1][j];
      }
    }
    cout<<dp[s_l][p_l]<<"\n";
  }
}