#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>
#include <string>

using namespace std;


int check_winner(vector<vector<int>> ballot,vector<int> priorities, vector<int>& count_priorities,vector<int> discard, int length, int voters, vector<string> contestants){
    int select_priority;
    int winner_majority = -1;

    // Counting the priorities of each voter.
    for(int i=0;i<voters;i++){
        select_priority = priorities[i];
        int choice = ballot[i][select_priority];
        count_priorities[choice - 1]++;
    }

    while(winner_majority==-1){

        //Update priorities of each voter

        for(int i=0;i<voters;i++){
            int l = 0;
            select_priority = priorities[i];
            int choice = ballot[i][select_priority];
            while(discard[choice-1]){
                priorities[i]++;
                choice = ballot[i][priorities[i]];
                l = 1;
            }
            if(l){
                select_priority = priorities[i];
                int choice = ballot[i][select_priority];
                count_priorities[choice - 1]++;
            }
        }

        // Checking the highest and lowest votes to declare the winner/discard the candidate with lowest votes.
        int min = 1001;
        int max = 0;

        for(int i=0;i<count_priorities.size();i++){
            if(discard[i]) continue;
            if(count_priorities[i]>max) {
                max = count_priorities[i];
            }
            if(count_priorities[i]<min){
                min = count_priorities[i];
            }
        }

        // If majority is >50% or the candidates left have the same voting percentage.
        if(max>voters/2 || max == min){
            winner_majority = max;
        }
        else{
            for(int i=0;i<length;i++){
                if(count_priorities[i] == min) discard[i] = 1;
            }
        }
    }
    return winner_majority;
}

int main()
{
    int cases;
    cin>>cases;
    int q = 0;
    while(cases--){
        q++;
        int n;
        cin>>n;
        cin.ignore();

        vector<string> contestants;
        char name[81];

        for(int i=0;i<n;i++){
            cin.getline(name, 81);
            contestants.push_back(name);
        }

        vector<vector<int>> ballot;

        //int row = 0;
        string vote;
        int k;
        //vector<int> t;

        while(getline(cin, vote)){
            stringstream s(vote);
            if(vote.empty()) break;
            vector<int> votes;
            while(s>>k){
                votes.push_back(k);
            }
            ballot.push_back(votes);
        }

        int voters = ballot.size();
        vector<int> priorities(voters, 0);
        vector<int> count_priorities(n, 0);
        vector<int> discard(n, 0);

        int winner_majority = check_winner(ballot, priorities, count_priorities, discard, n, voters, contestants);

        if(q!=1){
            cout<<"\n";
        }
        for(int i=0;i<count_priorities.size();i++){
                if(count_priorities[i] == winner_majority){
                    if(discard[i]==0){
                        cout<<contestants[i]<<"\n";
                    }
                }
            }
    }
    return 0;
}
