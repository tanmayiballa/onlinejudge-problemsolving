#include<iostream>
#include<bits/stdc++.h>
#include<list>

using namespace std;

int dice_roll[13][5];
int max_score = 0;
int dp[14][14];
vector<int> scores;
vector<int> max_score_indexes;

bool similar_dice(int chance, int count){
  vector<int> chance_sorted;
  for(int i=0;i<5;i++) chance_sorted.push_back(dice_roll[chance][i]);
  sort(chance_sorted.begin(), chance_sorted.end());
  int i = 0;
  int j = i+1;
  bool verdict = false;
  while(i<5 && j<5){

    if(chance_sorted[i] == chance_sorted[j]) j++;
    else {
      i=j;
      j = j+1;
    }

    if(j-i+1 == count && chance_sorted[i] == chance_sorted[j]){
      return true;
    }

  }
  return verdict;
}

bool fullhouse(int chance){
    vector<int> chance_sorted;
    for(int i=0;i<5;i++) chance_sorted.push_back(dice_roll[chance][i]);
    sort(chance_sorted.begin(), chance_sorted.end());

    if(chance_sorted[0] == chance_sorted[4]) return true;

    int i = 0;
    int j = i+1;
    bool verdict = false;
    int number = 0;
    int count = 3;
    // Checking 3 of a kind.
    while(i<5 && j<5){
    if(chance_sorted[i] == chance_sorted[j]) j++;
    else {
      i=j;
      j = j+1;
    }

    if((j-i+1 == count) && chance_sorted[i] == chance_sorted[j]){
      verdict = true;
      number = chance_sorted[i];
      break;
    }

  }
  //cout<<verdict<<number<<"\n";
    if(!verdict) return false;

    // Checking 2 of a kind.
    count = 2;

    i = 0;
    j = i+1;
    while(i<5 && j<5){

    if(chance_sorted[i] == chance_sorted[j] && chance_sorted[i]!=number) return true;
    else {
      i=j;
      j = i+1;
    }
  }
    return false;
}

bool sequence(int chance, int count){

    vector<int> chance_sorted;
    for(int i=0;i<5;i++) chance_sorted.push_back(dice_roll[chance][i]);
    sort(chance_sorted.begin(), chance_sorted.end());

    int i = 0;
    int j = i+1;
    int cnt = 0;

    while(j<5){
      if(chance_sorted[j] - chance_sorted[i] == 1){
        cnt++;
      }
      else if(chance_sorted[j] == chance_sorted[i]){
          i++;
          j++;
          continue;
      }
      else {
          if(cnt >= count-1) return true;
          cnt = 0;
      }
      i++;
      j++;
    }
    if(cnt>=count-1) return true;
    return false;
}

int category_score(int chance, int category){
  int score = 0;
  if(category >=1 && category <=6){
    for(int i=0;i<5;i++){
      if(dice_roll[chance][i] == category) score+=dice_roll[chance][i];
    }
    return score;
  }

  else if(category == 7){
    for(int i=0;i<5;i++) score+=dice_roll[chance][i];
    return score;
  }

  else if(category == 8){
    if(similar_dice(chance, 3)){
      for(int i=0;i<5;i++) score+=dice_roll[chance][i];
      return score;
    }
    return 0;
  }

  else if(category == 9){
    if(similar_dice(chance,4)){
      for(int i=0;i<5;i++) score+=dice_roll[chance][i];
      return score;
    }
    return 0;
  }

  else if(category == 10){
    if(similar_dice(chance,5)){
      return 50;
    }
    return 0;
  }

  else if(category == 11){
    if(sequence(chance, 4)) return 25;
    return 0;
  }

  else if(category == 12){
    if(sequence(chance,5)) return 35;
    return 0;
  }

  else if(category == 13){
    if(fullhouse(chance)) return 40;
    return 0;
  }

  return score;

}

void compute_dp_matrix(){
  for(int i=0;i<13;i++){
    for(int j=1;j<=13;j++){
      dp[i][j-1] = category_score(i, j);
    }
  }
  return;
}

void roll_assignment(int *roll){
  for(int i=0;i<13;i++){
    roll[i] = -1;
  }
  int S = 8191;

  for(int n=13;n>=1;n--){
    roll[n-1] = max_score_indexes[S];
    int shift = roll[n-1];
    S = S ^ (1<<shift);
  }
  return;
}

int yahtzee(int subset, int n){

  if(scores[subset]!=-1 || n==0) return scores[subset];

  int max_score = -1;
  int new_subset;
  int chance_max_score;


  for(int i=0,j=1; i<13; i++, j<<=1){
    if( (j&subset) == 0) continue;
    new_subset = subset ^ j;
    int tmp_score =  yahtzee(new_subset, n-1) + dp[i][n-1];

    if(n==6 && tmp_score>=63) tmp_score+=35;

    if(tmp_score>max_score){
      max_score = tmp_score;
      chance_max_score = i;
    }
  }
  scores[subset] = max_score;
  max_score_indexes[subset] = chance_max_score;
  return max_score;
}

void print_output(int *roll) {
  int score;
  int top_half_score = 0;
  int bottom_half_score = 0;
  int bonus = 0;

  for (int i=0; i < 13; i++) {
    cout<<dp[roll[i]][i]<<" ";
  }
  for (int i=0; i < 13; i++) {
    score = dp[roll[i]][i];
    if (i < 6) top_half_score += score;
    else bottom_half_score += score;
  }
  if(top_half_score>=63) bonus = 35;

  cout<<bonus<<" ";
  cout<<top_half_score+bottom_half_score+bonus;
  return;
}

int main(){
    int k;
  while(cin>>k){
      dice_roll[0][0] = k;
    for(int i=0;i<13;i++){
        for(int j=0;j<5;j++){
            if(i==0 && j==0) continue;
          cin>>dice_roll[i][j];
        }
    }
    //if(check != 65) break;

    for(int i=0;i<13;i++){
      for(int j=1;j<=13;j++){
        dp[i][j-1] = -1;
      }
    }
    compute_dp_matrix();
    scores.clear();
    max_score_indexes.clear();

      for(int i=0;i<8192;i++){
          scores.push_back(-1);
          max_score_indexes.push_back(-1);
      }
      scores[0] = 0;
    int sum = yahtzee(8191, 13);
    int roll[13];
    roll_assignment(roll);

    //for(int i=0;i<13;i++) cout<<dp[roll[i]][i]<<" ";
    print_output(roll);

    //for(int i=0;i<scores.size();i++) cout<<scores[i]<<" ";

    //cout<<sum<<"\n";
    cout<<"\n";

  }
}
