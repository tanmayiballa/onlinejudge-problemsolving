#include<iostream>
#include<bits/stdc++.h>

using namespace std;

map<string,int> map_config;

void initialize(){
  map_config.clear();
}

int min_buttons(string start, string end){

  if(start == end) return 0;
  
  queue<string> q;
  queue<int> qk;

  map_config[start] = 1;

  q.push(start);
  qk.push(1);
  while(!q.empty()){
    string curr = q.front();
    int curr_cnt = qk.front();
    q.pop();
    qk.pop();
    string tmp = curr;
    
    for(int i=0;i<4;i++){
      int j = -1;
      for(int j=-1;j<=1;j++){
        if(j==0) continue;
          string tmp = curr;
          int new_num = (tmp[i] - '0') + j;
          tmp[i] = new_num + '0';
          if(tmp[i] < '0'){
            tmp[i] = '9';
          }
          else if(tmp[i] > '9'){
            tmp[i] = '0';
          }
          if(map_config[tmp] != 0) 
            continue;
          if(tmp == end) 
            return curr_cnt;
          map_config[tmp] = curr_cnt + 1;
          q.push(tmp);
          int g = curr_cnt + 1;
          qk.push(g);
      }
    }
    }
  
  return -1;
}

int main(){
  int t;
  cin>>t;
  while(t--){
    initialize();
    char ch;
    string startS = "";
    string targetS = "";
    for(int i=0;i<4;i++){
      cin>>ch;
      startS+=ch;
    }
    for(int i=0;i<4;i++){
      cin>>ch;
      targetS+=ch;
    }
    int k;
    cin>>k;
    vector<string> forbid;
    string config = "";
    while(k--){
      config = "";
      char ch;
      for(int i=0;i<4;i++){
        cin>>ch;
        config+=ch;
      }
      forbid.push_back(config);
      map_config[config]  = -1;
    }
    
    cout<<min_buttons(startS, targetS)<<"\n";
  }
}