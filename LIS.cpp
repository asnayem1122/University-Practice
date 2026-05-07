#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>dp;

int LIS(int prev, int i, vector<int>&arr){
    if(i == arr.size()){
        return 0;
    }

    if(dp[i][prev+1] != -1) return dp[i][prev+1];

    int take = 0, skip = 0;

    if(prev == -1 || arr[prev] < arr[i]){
        take = 1 + LIS(i, i+1, arr);
    } 
    skip = LIS(prev, i+1, arr);

    return dp[i][prev+1] = max(take, skip);
}


int main() {
    vector<int>arr;
    
    int x;
    while(cin>>x){
        arr.push_back(x);
    }

    dp.assign(arr.size()+1, vector<int>(arr.size()+1, -1));
    
    cout<<LIS(-1, 0, arr);


    return 0;
}