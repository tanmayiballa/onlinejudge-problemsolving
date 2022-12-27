#include<iostream>
#include<bits/stdc++.h>
#include<cmath>

using namespace std;

int main(){
  double s;
  while(cin>>s){
    double a,b,c;
    c = 4*s*s*(1 - (3*sqrt(3) + 2*M_PI)/12);
    b = 4*(s*s - M_PI*s*s/4 - c/2);
    a = (s*s - b - c);
    cout<<fixed<<setprecision(3)<<a<<" "<<b<<" "<<c<<"\n";
  }
}