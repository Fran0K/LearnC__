//
// Created by Frank Lin on 06/03/2022.
//

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i =0;i<n;i++){
            if(nums[i]>0){
                break;
            }
            int l =i+1;
            int r =n-1;
            if(nums[l]==nums[r]){
                continue;
            }
            while(l<r){
                if(nums[l]+nums[i]+nums[r]==0){
                    vector<int> temp;
                    temp.push_back(nums[l]);
                    temp.push_back(nums[i]);
                    temp.push_back(nums[r]);
                    ans.push_back(temp);
                    break;
                }
                else if(nums[l]+nums[i]+nums[r]<0){
                    l++;
                }else{
                    r--;
                }
            }

        }
        std::cout<<"endl";
        return ans;

    }
};

int main(){
    vector<int> nums={0,0,0,0};
    Solution().threeSum(nums);

}

