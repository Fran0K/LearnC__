//
// Created by Frank Lin on 21/2/22.
//
#include <vector>
using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param array int整型vector
     * @return int整型vector
     */
    vector<int> FindGreatestSumOfSubArray(vector<int>& array) {
        // write code here
        int n = array.size();
        vector<int> dp(n+1,0);
        int left =0;
        int right = 0;
        for(int i =0; i<n ; i++){
            dp[i] = max(dp[i-1]+array[i], dp[i-1]);
            if(dp[i] == dp[i-1]){
                left = right;
            }else{
                right++;
            }
        }

        vector<int> ans;
        for(int i = left; i<=right;i++){
            ans.push_back(array[i]);
        }
        return ans;

    }
};

int main(){
    vector<int> a= {1,-2,3,10,-4,7,2,-5};
    Solution().FindGreatestSumOfSubArray(a);
}