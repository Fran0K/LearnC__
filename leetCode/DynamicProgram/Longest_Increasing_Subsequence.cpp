//
// Created by Frank Lin on 29/10/21.
//
#include <iostream>
#include <vector>
using namespace std;
int lengthOfLIS(vector<int>& nums) {
    vector<int> dp(nums.size(), 1);
    int res = 0;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }
    return res;

}

int main(){
    int arr[] ={4,10,4,3,8,9};
    //int arr[] ={0,1,0,3,2,3};
    int size = sizeof(arr)/ sizeof(arr[0]);
    vector<int> num (arr, arr+size);
    int kk = lengthOfLIS(num);
    cout<<kk;
}