#include<iostream>
#include<bits/stdc++.h>
#include<cmath>

using namespace std;

double min_rope(double x1,double y1, double x2, double y2, double r){
  double L1,L2,A1,A2,T,P,D,K1,K2;

  L1 = sqrt(x1*x1 + y1*y1);
  L2 = sqrt(x2*x2 + y2*y2);

  A1 = acos(r/L1);
  A2 = acos(r/L2);

  D = sqrt(pow(x2-x1,2) + pow(y2-y1,2));
  P = acos((L1*L1 + L2*L2 - D*D)/(2*L1*L2));
  T = P - A1 - A2;

  if(A1+A2>P) return D;

  K1 = sqrt(L1*L1 - r*r); 
  K2 = sqrt(L2*L2 - r*r);

  return K1+K2+T*r;
}

int main(){
  int t;
  cin>>t;
  while(t--){
    double x1,y1,x2,y2,r;
    cin>>x1>>y1>>x2>>y2>>r;

    // When the co-ordinates are not touching the circle

    cout<<fixed<<setprecision(3)<<min_rope(x1,y1,x2,y2,r)<<"\n";
  }
}