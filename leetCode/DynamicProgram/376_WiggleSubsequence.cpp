//
// Created by Frank Lin on 25/1/22.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int>down(n,1);
        vector<int>up(n,1);
        for(int i =1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                down[i] = down[i-1];
                up[i] = down[i-1]+1;
            }
            else if(nums[i]<nums[i-1]){
                up[i] = up[i-1];
                down[i] = up[i-1]+1;
            }else{
                up[i] = up[i-1];
                down[i] = down[i-1];
            }
        }
        return max(down[n-1], up[n-1]);
    }
};

int main(){
    vector<int> nums={1,7,4,9,2,5};
    int k = Solution().wiggleMaxLength(nums);
    cout<<k;
}