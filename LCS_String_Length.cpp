#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>dp;
string s3;

int LCS(int i , int j, string s1, string s2){
    if(i == s1.length() || j == s2.length()){
        return 0;
    }
    int take = 0, skip = 0;
    
    if(s1[i] == s2[j]){
        take =  1 + LCS(i+1, j+1, s1, s2);
        s3+=s1[i];
        return take;
    }

    skip =  max(LCS(i+1, j, s1, s2), LCS(i, j+1, s1, s2));
    return skip;
}


int main() {
    string s1, s2;
    cin>>s1>>s2;

    dp.assign(s1.length()+1, vector<int>(s2.length(), -1));

    cout<<LCS(0, 0, s1, s2)<<endl;

    reverse(s3.begin(), s3.end());

    cout<<s3;

    return 0;
}