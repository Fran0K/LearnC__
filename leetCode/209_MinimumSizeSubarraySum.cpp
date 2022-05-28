//
// Created by Frank Lin on 23/5/2022.
//
#include "vector"

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n =nums.size();

        int mi=INT_MAX;
        int l=0,r=0;
        int sum =0;
        while(r<n){
            int a1 = nums[r];
            sum+=a1;
            if(sum==target){
                mi = min(r+1-l,mi);
            }else if(sum>target){
                while(sum>target){
                    sum-=nums[l];
                    l++;
                }
                if(sum==target){
                    mi = min(r+1-l,mi);
                }
            }
            r++;

        }
        if(sum==target){
            mi = min(r+1-l,mi);
        }
        return mi;
    }
};

int main(){
    int target = 11;
    vector<int>nums = {1,2,3,4,5};

    Solution().minSubArrayLen(target, nums);
}