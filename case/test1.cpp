//
// Created by Frank Lin on 13/2/22.
//

#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            int sum = 1;
            int zeroCount = 0;
            int n = nums.size();
            vector<int> ans(n,0);

            for(int i =0;i<n;i++){
                if(nums[i]!= 0){
                    sum*=nums[i];
                }else{
                    zeroCount++;
                }
            }
            if(zeroCount>1){
                return ans;
            }else if(zeroCount=1){
                for(int i =0;i<n;i++){
                    if(nums[i]==0){
                        ans[i] = sum;
                    }
                }
            }else{
                for(int i =0;i<n;i++){
                    ans[i] = sum/nums[i];
                }
            }
            return ans;
        }
};

int main(){
    vector<int> nums={0,4,0};
    Solution().productExceptSelf(nums);
    return 0;
}