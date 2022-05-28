//
// Created by Frank Lin on 02/04/2022.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, INT_MAX);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int j=0; j<n;j++){
                if(i>= coins[j]){
                    int b=dp[i-coins[j]];
                    dp[i] = min(dp[i], b+1);
                }
            }

        }
        return dp[amount];

    }
};

int main(){
    int account =11;
    vector<int> nums={1, 2, 5};
    Solution().coinChange(nums,account);

}
