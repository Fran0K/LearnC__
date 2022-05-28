//
// Created by Frank Lin on 27/03/2022.
//

#include <vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0 || m==0){
            if(n==0){
                return;
            }else{
                for(int i = 0;i<n;i++){
                    nums1[i]=nums2[i];
                }
                return;
            }
        }
        int end = m+n-1;
        m--;
        n--;
        while(m>=0 && n>=0){
            if(nums2[n] > nums1[m]){
                nums1[end] = nums2[n--];
            }else{
                nums1[end] = nums1[m--];
            }
            end--;
        }
        //第一完
        if(m<0){
            for(int i = n;i>=0;i--){
                nums1[end] = nums2[i];
                end--;
            }
        }
//        if(n<0){
//            for(int i = m;i>=0;i--){
//                nums1[end] = nums1[i];
//                end--;
//            }
//        }

    }
};

int main(){
    vector<int> v={2,0};
    vector<int> v2={1};

    Solution().merge(v,1,v2,1);
}