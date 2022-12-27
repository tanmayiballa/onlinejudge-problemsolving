#include <iostream>
#include <bits/stdc++.h>
#include<unordered_map>

using namespace std;

bool check_doublets(vector<string> fragments, int i, string pattern, int res_size, int n, vector<bool> visited){
  int cnt = 1;
  for(int j = 1; j<n;j++){
    if(visited[j]) continue;
      for(int k = j+1;k<n;k++){
          if(visited[k]) continue;
          if(fragments[j] + fragments[k] == pattern) {
              visited[j] = true;
              visited[k] = true;
              cnt++;
          }
          else if(fragments[k] + fragments[j] == pattern){
              visited[j] = true;
              visited[k] = true;
              cnt++;
          }
        }
  }

  if(cnt == n/2) return true;
  return false;
}


int main()
{
    int t;
    cin>>t;
    string frag;
    getline(cin,frag);
    getline(cin,frag);
    bool flag = false;

    while(t--){
        //cout<<"Hello"<<"\n";
        if(flag) cout<<"\n";
        flag = true;
        vector<string> fragments;
        vector<bool> visited;
        string frag;
        int cnt = 0;
        //cout<<"asjdk"<<" "<<frag;
        while(getline(cin,frag)){
            if(frag.length() == 0) break;
            fragments.push_back(frag);
            visited.push_back(false);
            cnt+=frag.length();
            //cout<<frag<<"\n";
        }
        int n = fragments.size();
        int res_size = ((cnt*2)/n);
        //cout<<n<<res_size<<"\n";

        visited[0] = true;
        for(int i=1;i<n;i++){
            //cout<<i<<"\n";
          string pattern = fragments[i] + fragments[0];
          string rev_pattern = fragments[0] + fragments[i];
          visited[i] = true;
          if(check_doublets(fragments,i, pattern, res_size, n, visited)){
            cout<<pattern<<endl;
            break;
          }
          else if(check_doublets(fragments,i,rev_pattern, res_size, n, visited)){
            cout<<rev_pattern<<endl;
            break;
          }
          visited[i] = false;
        }
    }

    return 0;
}
