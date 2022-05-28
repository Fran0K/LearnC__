//
// Created by Frank Lin on 5/2/22.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i =2;i<n;i++){
            dp[i] = cost[i]+min(dp[i-2], dp[i-1]);
        }
        return dp[n-1];

    }
};

int main(){
    vector<int> kk ={10,15,20};
    int k =Solution().minCostClimbingStairs(kk);
    cout<<k<<endl;
}