//
// Created by Frank Lin on 19/4/2022.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        if(n==1){
            return true;
        }
        vector<int>dp(n+1,0);
        int end = n/2;
        vector<int>nums={2,3,5};
        for(int i=1;i<=end;i++){
            for(int j = 0;j<3;j++){
                int k = i*nums[j];
                if(k<n){
                    dp[k]=k;
                }else if(k==n){
                    return true;
                }
            }
        }
        return dp[n]==0?false:true;


    }
};

int main(){
    int k =6;
    Solution().isUgly(k);
}