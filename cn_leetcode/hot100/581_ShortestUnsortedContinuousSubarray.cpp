//
// Created by Frank Lin on 09/03/2022.
//

#include <vector>
using namespace std;
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n =nums.size();
        int start = 0;
        int end = -1;
        int mx =nums[0];
        int mi = nums[n-1];
        for(int i =0;i<n;i++){
            if(nums[i]<mx){
                end = i;
            }else{
                mx = nums[i];
            }
            if(nums[n-i-1]>mi){
                start = n-i-1;
            }else{
                mi = nums[n-1-i];
            }
        }
        return end-start+1;

    }
};

int main(){
    vector<int> nums={2,6,4,8,10,9,15};
    Solution().findUnsortedSubarray(nums);
}