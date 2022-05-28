//
// Created by Frank Lin on 28/5/2022.
//
#include "vector"
#include "numeric"
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum =accumulate(nums.begin(),nums.end(),0);

        //计算总数

        //如果是奇数
        int target = sum/2;
        if(sum%2==1){
            return false;
        }

        vector<vector<bool>>dp(n+1,vector<bool>(target+1));
        //base case;
        for(int i =0;i<n;i++){
            dp[i][0]= true;
        }

        for(int i =1;i<=n;i++){
            for(int j= 1; j<=target;j++){
                //能装
                if(j-nums[i-1]>=0){
                    dp[i][j] = dp[i-1][j]||dp[i-1][i-nums[j]];
                }else{
                    //不能装
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[target][n-1];


    }
};

int main(){
    vector<int>a={1,5,11,5};
    Solution().canPartition(a);
}
