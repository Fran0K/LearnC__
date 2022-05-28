//
// Created by Frank Lin on 1/3/22.
//
#include <vector>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n =nums.size();
        int i=n-2,j=n-1;
        while(i>=0 && nums[i]>nums[j]){
            j--;
            i--;
        }
        if(i>=0){
            for(int x =j;x<n;x++ ){
                if(nums[x]>nums[i]){
                    int tmp = nums[i];
                    nums[i] = nums[x];
                    nums[x] = tmp;
                    break;
                }
            }
        }

        reverse(nums.begin()+j, nums.end());
    }
};
int main(){
    vector<int> a={1,3,2};
    Solution().nextPermutation(a);
}