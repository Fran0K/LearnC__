#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        //1st nums, 2rd index
        unordered_map<int, int> a;
        vector<int> ans(2);
        for(int i =0;i<n;i++){
            auto iter = a.find(target-nums[i]);
            if(iter != a.end()){
                ans[0] =iter->second;
                ans[1] =i;
                return ans;
            }else{
                a.insert(make_pair(nums[i],i));
            }
        }
        return ans;

    }
};

int main(){
    vector<int> ans={2,7,11,15};
    int target = 9;
    Solution().twoSum(ans, target);
}