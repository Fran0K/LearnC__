//
// Created by Frank Lin on 9/5/2022.
//
#include <vector>

using namespace std;
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>presum(n+1,0);
        for(int i=0;i<n;i++){
            presum[i+1] = nums[i]+presum[i];
        }
        int count =0;
        for(int i =1 ;i<=n;i++){
            for(int j =0;j<i;j++){
                int te = presum[i]-presum[j];
                if(te%k==0){
                    count++;
                }
            }
        }
        return count;
    }
};

int main(){
    vector<int>nums = {4,5,0,-2,-3,1};
    int k = 5;
    Solution().subarraysDivByK(nums,k);

}