//
// Created by Frank Lin on 04/03/2022.
//

#include <vector>

using namespace std;

class Solution {
public:
    int count =0;
    int findTargetSumWays(vector<int>& nums, int target) {
        dfs(nums,target,0, 0);
        return count;

    }
    void dfs(vector<int>& nums, int target,int ans, int start){
        if(start == nums.size()){
            if(target==ans){
                count++;
                return;
            }
            return ;
        }
        else{
            {
                // plus
                int temp = nums[start];
                dfs(nums, target,ans+temp,start+1);
                dfs(nums, target,ans-temp,start+1);
            }
        }
    }
};

int main(){
    vector<int> v = {1,1,1,1,1};
    int target =3;
    Solution().findTargetSumWays(v,target);

}