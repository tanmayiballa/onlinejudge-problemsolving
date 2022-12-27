#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int X, Y;
int GCD;

void ext_euclid(int m, int n){
  if(n == 0){
    X = 1;
    Y = 0;
    GCD = m;
    return;
  }

  ext_euclid(n, m%n);

  int new_x = Y;
  int new_y = X - (m/n)*Y;

  X = new_x;
  Y = new_y;

  return;
  
}

int main(){
  int m,n;
  while(cin>>m>>n){
    ext_euclid(m,n);
    cout<<X<<" "<<Y<<" "<<GCD<<"\n";
  }
}