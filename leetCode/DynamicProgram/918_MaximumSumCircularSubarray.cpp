//
// Created by Frank Lin on 4/12/21.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int maxSubarraySumCircular(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(2 * nums.size()+1, INT8_MIN);
    for(int i =0 ; i<2*n; i++){
        
        for(int j=0; j<i;j++){
            int k = j;
            if(j>n){
                k = j%n;
            }
            ans[i] = max(ans[i], ans[i]+nums[k]);
        }
    }
    max(nums.begin(), nums.end());
    return 0;
}

int main(){
    vector<int> nums = {1,-2,3,-2};
    int k =maxSubarraySumCircular(nums);
    return 0;
}