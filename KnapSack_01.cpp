#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>dp; //intiitalize dp vector

int knapSack_01(int i, int bag_size, vector<int>&cost, vector<int>&weight){
    //base case 
    if(i == cost.size() || bag_size == 0) return 0; //pointer array er soman hoile ar bage zayga na thakle

    if(dp[i][bag_size] != -1) return dp[i][bag_size]; // Dynamic base case 

    int item_value = cost[i];
    int item_weight = weight[i];


    //dhorar jonno karon dorkar hoy charar jonno karon lage na 
    int take = 0, skip = 0;
    if(item_weight <= bag_size){ 
            take = item_value + knapSack_01(i+1, bag_size - weight[i], cost, weight);  //item er size bag er zayga theke choto hoile bag e nibo,
            skip = knapSack_01(i+1, bag_size, cost, weight);
             return dp[i][bag_size] = max(take, skip);
        }

    skip = knapSack_01(i+1, bag_size, cost, weight);
    return dp[i][bag_size] = skip;
}



int main(){
    //input
    int maler_size, bag_size;
    cin>>maler_size>>bag_size;

    dp.assign(maler_size+1, vector<int>(bag_size+1, -1));

    vector<int>cost(maler_size), weight(maler_size);

    for(auto &i : cost){
        cin>>i;
    }

    for(auto &i : weight){
        cin>>i;
    }

    cout<<knapSack_01(0, bag_size, cost, weight);
    
}
