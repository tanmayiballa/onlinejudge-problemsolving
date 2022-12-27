#include <iostream>
#include <bits/stdc++.h>

#define inf 100000008;
using namespace std;

vector< vector<int> > moves;

int min_cross_time(vector<int> time){
  int len = time.size();
  int min_time = 0;
  int i;

  for(i=len-1;i>=0;i-=2){

    if(i == 2 || i == 1 || i == 0) break;

    int s1 = time[i] + 2*time[0] + time[i-1];
    int s2 = time[1] + time[0] + time[i] + time[1];

    if(s1<s2){
      vector<int> move;

      move.push_back(time[0]);
      move.push_back(time[i]);

      moves.push_back(move);
      //cout<<time[0]<<" "<<time[i-1]<<"\n";

      move.pop_back();
      moves.push_back(move);
      //cout<<time[0]<<"\n";
      move.push_back(time[i-1]);

      moves.push_back(move);
      //cout<<time[0]<<" "<<time[i-2]<<"\n";

      move.pop_back();
      //cout<<time[0]<<"\n";

      moves.push_back(move);
      min_time+=s1;
    }
    else{
      vector<int> move;

      move.push_back(time[0]);
      move.push_back(time[1]);
      moves.push_back(move);
      //cout<<time[0]<<" "<<time[1]<<"\n";
      move.pop_back();
      moves.push_back(move);
      //cout<<time[0]<<"\n";

      move.pop_back();
      move.push_back(time[i]);
      move.push_back(time[i-1]);

      moves.push_back(move);
      //cout<<time[i]<<" "<<time[i-1]<<"\n";

      move.pop_back();
      move.pop_back();
      move.push_back(time[1]);
      moves.push_back(move);
      //cout<<time[1]<<"\n";
      min_time+=s2;
    }
  }

  if(i==0){
    min_time+=time[0];
    vector<int> move;
    move.push_back(time[0]);
    moves.push_back(move);
    //cout<<time[0]<<"\n";
  }
  else if(i == 1){
    min_time+=time[1];
    vector<int> move;
    move.push_back(time[0]);
    move.push_back(time[1]);

    moves.push_back(move);
    //cout<<time[0]<<" "<<time[1]<<"\n";
  }
  else{
    min_time+=(time[0] + time[1] + time[2]);
    vector<int> move;
    move.push_back(time[0]);
    move.push_back(time[1]);
    moves.push_back(move);
    //cout<<time[0]<<" "<<time[1]<<"\n";
    move.pop_back();
    moves.push_back(move);
    //cout<<time[0]<<"\n";

    move.push_back(time[2]);
    moves.push_back(move);
    //cout<<time[0]<<" "<<time[2]<<"\n";
  }
  //cout<<min_time<<"\n";
  return min_time;
}

int main(){
  int t;
  cin>>t;

  while(t--){
    //cout<<"New Input"<<"\n";
    int n,k;
    moves.clear();
    cin>>n;
    vector<int> crossing_time;

    for(int i=0;i<n;i++){
      cin>>k;
      crossing_time.push_back(k);
    }

    sort(crossing_time.begin(), crossing_time.end());
    int min_tym = min_cross_time(crossing_time);
    cout<<min_tym<<"\n";
    for(int i=0;i<moves.size();i++){
      if(moves[i].size() == 2) {
        cout<<moves[i][0]<<" "<<moves[i][1];
      }
      else{
        cout<<moves[i][0];
      }
      cout<<"\n";
    }
    if(t!=0) cout<<"\n";

  }
}
