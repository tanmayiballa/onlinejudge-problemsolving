#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>
#include <string.h>

using namespace std;

void minimum_transfer(vector<int> money, int n){
    //calculating the mean of the amount spent.
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=money[i];
    }

    int mean = sum/n;
    int floor_value = mean;
    int ceil_value;
    if(sum%n!=0) ceil_value = floor_value+1;
    else ceil_value = floor_value;
    int count_highest_share = sum%n;

    int min_transfer = 0;

    // Sorting vector in descending order to assign higher share, mostly to the givers
    sort(money.begin(), money.end(), greater<int>());

    vector<int> share;

    // Assigning share value to each student.
    for(int i=0;i<n;i++){
        int share_val;
        if(count_highest_share){
            share_val = abs(money[i] - ceil_value);
            count_highest_share--;
        }
        else{
            share_val = abs(money[i] - floor_value);
        }
        share.push_back(share_val);
    }

    // Calculating the minimum transfer amount.
    for(int i=0;i<n;i++){
        if(money[i] > mean) continue;
        min_transfer+=share[i];
    }

    int dollar = min_transfer/100;
    int cents = min_transfer%100;

    cout<<"$"<<dollar<<".";
    cout<<right<<setfill('0')<<setw(2); // For 2 decimal precision for cents.
    cout<<cents<<"\n";

    return;
}

int main()
{
    int n;

    while(cin>>n){
        if(n==0) break;
        vector<int> money;
        int sum = 0;
        //float dollars;
        string amount;
        char delimeter = '.';
        for(int i=0;i<n;i++){
            cin>>amount;
            //cout<<amount<<"\n";
            string dollars = (amount.substr(0, amount.find(delimeter)));
            string cents = (amount.substr(amount.find(delimeter) + 1, amount.length()));
            int total = stoi(dollars)*100 + stoi(cents);
            money.push_back(total);
        }
        minimum_transfer(money,n);
    }

    return 0;
}
