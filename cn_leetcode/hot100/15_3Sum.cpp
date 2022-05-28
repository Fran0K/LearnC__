//
// Created by Frank Lin on 08/03/2022.
//

#include <vector>
using namespace std;
//class Solution {
//public:
//    vector<vector<int>> threeSum(vector<int>& nums) {
//        int n = nums.size();
//        vector<vector<int>> ans;
//        if(n<3){
//            return ans;
//        }
//        sort(nums.begin(), nums.end());
//        int i =0;
//        int l=0,r=1;
//        while(nums[i]<=0 && l<r){
//            l=i+1;
//            r = n-1;
//            while(l<=r && nums[i]+nums[l]+nums[r]<0){
//                l++;
//            }
//            while(l<=r && nums[i]+nums[l]+nums[r]>0){
//                r--;
//            }
//            if(l==r){
//                i++;
//                continue;
//            }
//            if(nums[i]+nums[l]+nums[r]==0){
//                vector<int> temp={nums[i],nums[l],nums[r]};
//                ans.push_back(temp);
//            }
//            i++;
//        }
//        return ans;
//    }
//};


//class Solution {
//public:
//    vector<vector<int>> threeSum(vector<int>& nums) {
//        int n = nums.size();
//        vector<vector<int>> ans;
//        if(n<3){
//            return ans;
//        }
//        sort(nums.begin(), nums.end());
//        for(int i =0;i<=n-2 && nums[i]<=0;i++){
//            int l =i+1;
//            int r = n-1;
//            if(i>0 && nums[i-1]==nums[i]){
//                continue;
//            }
//            while(l<r){
//                int sum = nums[i]+nums[l]+nums[r];
//                if(sum==0){
//                    vector<int> t = {nums[i],nums[l],nums[r]};
//                    ans.push_back(t);
//                    while(l<r && nums[l]==nums[l+1]){
//                        l++;
//                    }
//                    while(l<r && nums[r]==nums[r-1]){
//                        r--;
//                    }
//                    l++;
//                    r--;
//                }
//                else if(sum<0){
//                    l++;
//                }else{
//                    r--;
//                }
//            }
//        }
//        return ans;
//    }
//};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        if(n==0){
            return ans;
        }

        sort(nums.begin(), nums.end());
        for(int i =0; i<n-2&&nums[i]<=0;i++){
            int l = i+1, r = n-1;
            if(i>0 && nums[i] == nums[i+1]){
                continue;
            }
            while(l<r){
                int sum = nums[i]+nums[l]+nums[r];
                if(sum==0){
                    vector<int> temp ={nums[i],nums[l],nums[r]};
                    ans.push_back(temp);
                    while( l<r && nums[l+1]==nums[l] ){
                        l++;
                    }
                    while(l<r && nums[r-1]==nums[r] ){
                        r--;
                    }
                    l++;
                    r--;

                }else if(sum>0){
                    r--;
                }else{
                    l++;
                }
            }
        }
        return ans;

    }
};

int main(){
    vector<int> t={-1,0,1,2,-1,-4};
    Solution().threeSum(t);
}