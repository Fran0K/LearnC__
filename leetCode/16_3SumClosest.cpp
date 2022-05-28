//
// Created by Frank Lin on 18/5/2022.
//
#include "vector"

using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
--        int ans=0;
        if(n==3){
            for(auto p : nums){
                ans+=p;
            }
            return ans;
        }

        int mn = INT_MAX;
        int l =0,r=0;
        int sum = 0;

        while(r<n){
            if(abs(target-sum) < mn){
                mn = abs(target-sum);
                ans = sum;
            }
            sum+=nums[r++];
            sum-=nums[l++];
        }
        return ans;
    }
};

int main(){
    vector<int>num={1,1,1,0};
    int target = -100;
    Solution().threeSumClosest(num, target);

}