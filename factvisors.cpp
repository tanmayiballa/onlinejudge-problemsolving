#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int get_power(int n, int f){
  int cnt = 0;
  while(n%f == 0){
    cnt++;
    n = n/f;
  }
  return cnt;
}

bool factvisors(int m, int n){
  int tmp = n;
  bool divisibility = true;

  for(int i = 2; i<=sqrt(n);i++){
    int cnt1 = get_power(n,i);
    
    n = n/pow(i,cnt1);

    if(cnt1>0){
      int prime_fact = i;

      while(m/prime_fact){
        cnt1-=m/prime_fact;
        prime_fact*=i;
        if(cnt1<=0) break;
      }
      if(cnt1>0) divisibility = false;
    }
  }

  if(n>1 && divisibility == true){
    int prime_fact = n;

    int count = 1;

    while(m/prime_fact){
      count-=m/prime_fact;
      prime_fact*=n;
      if(count<=0) break;
    }
    if(count>0) divisibility = false;
  }
  
  return divisibility;
}

int main(){
  int m,n;
  while(cin>>m>>n){
    if(factvisors(m,n)) cout<<n<<" divides "<<m<<"!"<<"\n";
    else cout<<n<<" does not divide "<<m<<"!"<<"\n";
  }
}