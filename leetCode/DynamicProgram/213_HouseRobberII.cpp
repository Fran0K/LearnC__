//
// Created by Frank Lin on 6/12/21.
//
#include <iostream>
#include <vector>
using namespace std;

int rob(vector<int>& nums, int begin, int end) {
    int n = nums.size();
    if(n ==1){
        return nums[0];
    }else{
        vector<int> dp(2*n+1, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0] , nums[1]);
        for(int j =2 ;j<(2*n); j++){
            int i = j%n;
            dp[j] = max(dp[j-2]+nums[i], dp[j-1]);
        }
        int tt = dp[2*n-1]/2;
        return tt;
    }

}

int main(){
    vector<int>v ={200,3,140,20,10};
    rob(v,1,1);
    return 0;
}