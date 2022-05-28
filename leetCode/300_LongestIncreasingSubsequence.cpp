//
// Created by Frank Lin on 2/12/21.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int lengthOfLIS(vector<int>& nums) {
    vector<int> dp(nums.size(),1);
    int max =0;
    for(int i =0; i<nums.size(); i++){
        for(int j = 0 ;j<i;j++) {
            if (nums[i] > nums[j]) {
                dp[i] = std::max(dp[j] + 1, dp[i]);
            }
        }
        if(dp[i]>max){
            max = dp[i];
            }
        }
    return max;
}

int main(){
    vector<int> nums={10,9,2,5,3,7,101,18};
    int k = lengthOfLIS(nums);
    cout<<k;
    return 0;
}