#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<string> original_order;
vector<string> new_order;
unordered_map<string, int> orig_mapping;
unordered_map<string, int> new_mapping;

void shell_sort(){
  string prev_str = new_order[new_order.size()-1];
  //cout<<prev_str<<"\n";
  string curr_str;
  bool flag = false;
  vector<string> res;

  for(int i=new_order.size()-2;i>=0;i--){
    curr_str = new_order[i];
    //cout<<i<<" "<<curr_str<<"\n";
    int prev_index = orig_mapping[prev_str];
    int curr_index = orig_mapping[curr_str];

    if(curr_index < prev_index){
      prev_str = curr_str;
      continue;
    }

    flag = true;

    for(int j = i; j>=0; j--) res.push_back(new_order[j]);
    break;
  }

  for(int i=0;i<res.size();i++){
    cout<<res[i]<<endl;
  }
}

void initiate(){
  original_order.clear();
  new_order.clear();
  orig_mapping.clear();
  new_mapping.clear();
}
int main(){
  int t;
  cin>>t;
  //bool flag = false;
  while(t--){
    initiate();
    int n;
    string str;
    cin>>n;
    cin.ignore();
    cin.ignore();
    //flag = true;
    //cout<<t<<"\n";
    for(int i=0;i<n;i++){
      getline(cin, str);
      original_order.push_back(str);
      orig_mapping[str] = i;
      //cout<<str<<"o\n";
    }

    for(int i=0;i<n;i++){
      getline(cin, str);
      new_order.push_back(str);
      new_mapping[str] = i;
      //cout<<str<<"\n";
    }

    shell_sort();
    cout<<endl;
  }
}