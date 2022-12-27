#include<iostream>
#include<bits/stdc++.h>

using namespace std;

long G, X, Y, N;
bool valid = true;

void ext_euclid(int m, int n){
  if(n == 0){
    X = 1;
    Y = 0;
    G = m;
    return;
  }

  ext_euclid(n, m%n);

  long new_x = Y;
  long new_y = X - (m/n)*Y;

  X = new_x;
  Y = new_y;

  return;
  
}

void solution_exists(long n1,long n2,long c1,long c2){
  
  if(N%G != 0){
    valid = false;
    return;
  }

  X = X * (N/G);
  Y = Y * (N/G);
  
  n2 = n2/G;
  n1 = n1/G;
  
  long k_left = ceil(-(double) X/n2);
  long k_right = floor((double)Y/n1);

  if(k_left>k_right){
    valid = false;
    return;
  }

  long total_cost = c1*n2 - c2*n1;

  if(total_cost*k_left < total_cost*k_right){
    X = X + n2*k_left;
    Y = Y - n1*k_left;
  }
  else{
    X = X + n2*k_right;
    Y = Y - n1*k_right;
  }

  return;
}

int main(){
  while(cin>>N){
    valid = true;
    if(N==0) break;
    long n1,n2,c1,c2;
    cin>>c1>>n1;
    cin>>c2>>n2;

    // Compute m1 & m2 using extended Euclid algorithm
    ext_euclid(n1,n2);
    solution_exists(n1,n2,c1,c2);
    if(valid) cout<<X<<" "<<Y<<"\n";
    else cout<<"failed"<<"\n";
  }
}