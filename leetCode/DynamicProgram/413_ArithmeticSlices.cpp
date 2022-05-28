//
// Created by Frank Lin on 22/12/21.
//

#include <iostream>
#include <vector>

using namespace std;
int numberOfArithmeticSlices(vector<int>& nums) {
    if(nums.size() <3){
        return 0;
    }
    int last_diff = nums[1] - nums[0];
    int ans =0;
    int cur = 0;
    for(int i = 2; i< nums.size(); i++){
        int cur_diff = nums[i] - nums[i-1];
        if(last_diff == cur_diff){
            cur++;
        }else{
            last_diff = cur_diff;
            cur =0;
        }
        ans += cur;
    }
    return ans;
}

int main(){
    vector<int> v{1,2,3,8,9,10};
    numberOfArithmeticSlices(v);
    return 0;
}