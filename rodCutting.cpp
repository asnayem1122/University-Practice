#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>dp;

int rod_cutting(vector<int>&rod, int i, int len){

    if(i >= rod.size() || len == 0) return 0;

    if(dp[i][len] != -1) return dp[i][len];

    int take = 0;
    if(i <= len){
        take = rod[i] + rod_cutting(rod, i, len - i);
    }

    int skip = rod_cutting(rod, i+1, len);

    return dp[i][len] = max(take, skip);

}

int main() {
    
    int size, rod_len;

    cin>>size>>rod_len;

    vector<int>rod(size);

    dp.assign(size+1, vector<int>(rod_len+1, -1));
    
    for(auto &i : rod){
        cin>>i;
    }


    cout<<rod_cutting(rod, 1, rod_len);

    return 0;
}