//
// Created by Frank Lin on 28/5/2022.
//
#include "vector"

using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum =0;

        //计算总数
        for(auto p:nums){
            sum+=p;
        }
        //如果是奇数
        if(sum%2==1){
            return false;
        }

        vector<vector<bool>>dp(n,vector<bool>(sum+1));
        //base case;
        for(int i =0;i<n;i++){
            dp[i][0]= true;
        }

        for(int i =1;i<=sum;i++){
            for(int j= 0; j<n;j++){
                //能装
                if(i-nums[j]>=0){
                    dp[i][j] = dp[i][j]||dp[i-nums[j]][j];
                }else{
                    //不能装
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[sum][n-1];


    }
};

int main(){
    vector<int>a={1,5,11,5};
    Solution().canPartition(a);
}
