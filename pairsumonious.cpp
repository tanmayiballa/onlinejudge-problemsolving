#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int> A;
vector<int> X;
vector<int> tmp_X;

bool remove(int ele){
  auto it = find(tmp_X.begin(), tmp_X.end(), ele);
  if(it==tmp_X.end()) return false;
  int index = distance(tmp_X.begin(), it);
  tmp_X.erase(tmp_X.begin()+index);
  return true;
}

bool solve(int i){
  int smallest_A = i;
  A.clear();
  A.push_back(smallest_A);

  tmp_X = X;

  while(tmp_X.size()!=0){
    int smallest_sum = tmp_X[0];
    int next_A = smallest_sum - smallest_A;

    for(int j = 0;j<A.size();j++){
      if(!remove(next_A + A[j])) return false;
    }
    A.push_back(next_A);
  }
  return true;
}

int main(){
  int n;
  while(cin>>n){
    int num;
    int k = (n*(n-1))/2;
    X.clear();
    tmp_X.clear();
    A.clear();

    for(int i=0;i<k;i++){
      cin>>num;
      X.push_back(num);
    }

    sort(X.begin(),X.end());

    int smallest_sum = X[0];

    // The smallest element will always be between 0 - smallest_sum/2;

    for(int i=2;i<k;i++){
      int sum = X[0] + X[1] - X[i];
      if(solve(sum/2)) break;
    }

    if(tmp_X.size()==0){
      for(int i=0;i<A.size();i++){
        cout<<A[i];
        if(i!=A.size()-1) cout<<" ";
      }
      cout<<"\n";
    }
    else cout<<"Impossible"<<"\n";
  }
}
