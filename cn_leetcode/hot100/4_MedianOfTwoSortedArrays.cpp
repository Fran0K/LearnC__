//
// Created by Frank Lin on 09/03/2022.
//

#include <vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<int>dp(n+m,0);

        int i =0;
        int j =0;
        int x =0;
        if(i+j<n+m){
            while(i<n && j<m){
                if(nums1[i]<nums2[j]){
                    dp[x] = nums1[i];
                    i++;
                }else{
                    dp[x] = nums2[j];
                    j++;
                }
                x++;
            }
            while(i<n){
                dp[x] = nums1[i];
                i++;
                x++;
            }
            while(j<m){
                dp[x] = nums2[j];
                j++;
                x++;
            }
        }
        int k =0;

        if( (m+n)%2 == 1){
            k = (m+n-1)/2;
            return double(dp[k]);
        }else{
            k = (m+n)/2;
            return double((dp[k]+dp[k-1]))/2;
        }

    }
};

int main(){
    vector<int> v1 ={1,2};
    vector<int> v2 ={3,4};
    Solution().findMedianSortedArrays(v1,v2);
}