#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int LCS(int i, int j, string &s1, string &s2){

    // base case
    if(i == s1.length() || j == s2.length()){
        return 0;
    }

    // memoization
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    // match
    if(s1[i] == s2[j]){
        return dp[i][j] = 1 + LCS(i+1, j+1, s1, s2);
    }

    // not match
    return dp[i][j] = max(
        LCS(i+1, j, s1, s2),
        LCS(i, j+1, s1, s2)
    );
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;

    dp.assign(s1.length()+1,
              vector<int>(s2.length()+1, -1));

    cout << "Length = " << LCS(0, 0, s1, s2) << endl;

    // reconstruct LCS string
    int i = 0, j = 0;
    string ans = "";

    while(i < s1.length() && j < s2.length()){

        // character matched
        if(s1[i] == s2[j]){
            ans += s1[i];
            i++;
            j++;
        }

        // move according to larger dp value
        else if(dp[i+1][j] > dp[i][j+1]){
            i++;
        }
        else{
            j++;
        }
    }

    cout << "LCS = " << ans << endl;

    return 0;
}