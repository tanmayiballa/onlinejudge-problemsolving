#include<iostream>
#include<bits/stdc++.h>

using namespace std;


vector<string> dictionary;
vector<string> final_path;
unordered_map<string, string> prev_node;
unordered_map<string, bool> visited;
unordered_map<string, int> distances;

void bfs(string begin, string target){
    queue<string> q;
    for(int i=0;i<dictionary.size();i++){
        visited[dictionary[i]] = false;
        distances[dictionary[i]] = 30000;
        prev_node[dictionary[i]] = dictionary[i];
    }
    q.push(begin);
    visited[begin] = true;
    distances[begin] = 0;

    while(!q.empty()){
        string word = q.front();
        q.pop();

        for(int i=0;i<word.length();i++){
            for(char j = 'a'; j<='z';j++){
                if(word[i] == j) continue;

                string new_word = word;
                new_word[i] = j;

                if((visited.find(new_word)!=visited.end()) && visited[new_word] == false){
                    prev_node[new_word] = word;
                    distances[new_word] = distances[word] + 1;
                    visited[new_word] = true;
                    q.push(new_word);
                }
            }
        }
    }
}

int main(){

  string dict;
  string begin, target;
  int turns = 0;
  while(getline(cin, dict)){
      if(dict.length() == 0) break;
      dictionary.push_back(dict);
  }

  while(cin>>begin){
        cin>>target;
        if(turns) cout<<"\n";
        turns = 1;

        bfs(begin, target);

        if(distances[target] == 30000) cout<<"No solution."<<"\n";

        else{
            string path = target;
            vector<string> path_f;
            while(1){
                //cout<<path<<"\n";
                path_f.push_back(path);
                path = prev_node[path];
                if(path == begin) {
                    path_f.push_back(begin);
                    break;
                }
            }

            for(int i=path_f.size()-1;i>=0;i--){
                cout<<path_f[i]<<endl;
            }
        }
    }
    return 0;

}
