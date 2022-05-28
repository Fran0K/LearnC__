//
// Created by Frank Lin on 12/03/2022.
//
#include <vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m==0||n==0){
            if(m==0){
                for(int i =0;i<n;i++){
                    nums1[i] = nums2[i];
                }
            }
        }else{
            mergeA(nums1,m,nums2,n);
        }

    }
    void mergeA(vector<int>& nums1, int m, vector<int>& nums2, int n){
        int k = m+n-1;
        int i=m-1,j=n-1;
        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]){
                nums1[k] = nums1[i];
                i--;
            }else{
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
        if(i<0){
            while(j>=0){
                nums1[k--]=nums2[j--];
            }
        }
        if(j<0){
            while(i>=0){
                nums1[k--]=nums1[i--];
            }

        }
    }
};

int main(){
    vector<int> m1={2,0};
    int m = 1;
    vector<int> m2={1};
    int n =1;
    Solution().merge(m1,m,m2,n);
}