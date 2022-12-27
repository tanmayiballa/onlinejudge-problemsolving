#include<iostream>
#include<bits/stdc++.h>
#include<string>

using namespace std;

double chocochips[202][2];

int count(double x, double y,int n){
  int cnt = 0;
  double x1,y1;
  for(int i=1;i<=n;i++){
    x1 = chocochips[i][0]; y1 = chocochips[i][1];
    if((pow(x1-x,2) + pow(y1-y,2)) <= 6.25+0.000001) cnt++;
  }
  return cnt;
}

int max_chocochips(int n){
  int i,j;
  double x1,x2,y1,y2,d,xM,yM,xU,yU,t,xC,yC;
  //if(n==1) return 1;
  int cnt = 1;
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      if(i==j) continue;
      x1 = chocochips[i][0]; y1 = chocochips[i][1]; x2 = chocochips[j][0]; y2 = chocochips[j][1];
      d = sqrt(pow(x2-x1,2) + pow(y2-y1,2));
      //cout<<d<<"\n";
      if(d>5) continue;

      // check count for both centers;
      xM = (x1+x2)/2; yM = (y1+y2)/2;
      xU = (y1-y2)/d; yU = (x2-x1)/d;

      t = sqrt(6.25 - pow((d/2),2));

      xC = xM + t*xU;
      yC = yM + t*yU;
      cnt = max(cnt,count(xC,yC,n));

      xC = xM - t*xU;
      yC = yM - t*yU;

      cnt = max(cnt,count(xC,yC,n));
    }
  }
  return cnt;
}

int main(){
  int t;
  cin>>t;
  cin.ignore();
  cin.ignore();
  while(t--){
    double x1,x2;
    int n = 0;
    string input,s1,s2;
    double x,y;
    while(getline(cin,input)){
      if(input == "") break;
      n++;
      stringstream str(input);
      str>>s1>>s2;
      chocochips[n][0] = stod(s1); chocochips[n][1] = stod(s2);
    }
    cout<<max_chocochips(n)<<"\n";
    if(t) cout<<"\n";
  }
}