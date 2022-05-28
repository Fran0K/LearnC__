//
// Created by Frank Lin on 6/12/21.
//

#include <iostream>
#include <vector>
using namespace std;
bool canJump(vector<int>& nums) {
    int mx = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (i > mx) {
            return false;
        }
        mx = max(mx, i + nums[i]);
    }
    return true;

}

int main(){
    vector<int> nums= {3,2,1,0,4};
    bool k = canJump(nums);
    return 0;
}