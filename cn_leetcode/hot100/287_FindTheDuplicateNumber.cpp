//
// Created by Frank Lin on 03/03/2022.
//

#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int start = 1; int end = n;
        while(start<=end){
            int mid = start + (end - start)/2;
            int cnt = 0;
            for(auto num:nums){
                if(num<mid){
                    cnt++;
                }
            }
            if(cnt > mid){
                end = mid;
            }else{
                start = mid+1;
            }
        }
        return start;

    }

};

int main(){
    vector<int> nums={1,3,4,2,2};
    Solution().findDuplicate(nums);
}