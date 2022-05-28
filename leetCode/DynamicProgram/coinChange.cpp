//
// Created by Frank Lin on 28/10/21.
//
#include <iostream>
#include <vector>
using namespace std;
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1, amount+1);
    //dp[i]就是达成对应的硬币数
    dp[0]= 0;
    int ccount = 0;

    for(int i = 1; i<amount+1;i++){
        for(int j = 0; j <coins.size(); j++){
            if(coins[j]<=i) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    if(dp[amount] == amount+1){
        return -1;
    } else{
        int kk = dp[amount];
        return kk;
    }

}

int main(){
    vector<int> coins;
    //coins.push_back(1);
    coins.push_back(3);
    coins.push_back(5);

    int kk = coinChange(coins,11);
    cout<<kk;
    return 0;

}