//
// Created by Frank Lin on 05/03/2022.
//
#include <vector>
using namespace std;

//class Solution {
//public:
//    int search(vector<int>& nums, int target) {
//        int n=nums.size();
//        int start = 0;
//        int end = n-1;
//        if(nums[start]==target){
//            return start;
//        }
//        int index = -1;
//        while(start<end){
//            int mid = start +(end-start)/2;
//            //rotation binary
//            if(nums[start]>nums[end]){
//                if(nums[mid]>target){
//                    start=mid+1;
//                }else if(nums[mid]==target){
//                    index = mid;
//                    break;
//                }else{
//                    end = mid;
//                }
//            }else{
//                if(nums[mid]>target){
//                    end = mid;
//                }else if(nums[mid]==target){
//                    index = mid;
//                    break;
//                }else{
//                    start=mid+1;
//                }
//            }
//        }
//        return index;
//
//    }
//};


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int start = 0;
        int end = n-1;
        if(nums[start]==target){
            return start;
        }
        if(nums[end]==target){
            return end;
        }
        int index = -1;
        while(start<end){
            int mid = start +(end-start)/2;
            if(nums[mid] == target){
                index = mid;
                break;
            }
            //rotation binary
            if(nums[start]>nums[end]){
                if(nums[start] <= nums[mid]){
                    if(target>nums[start]){
                        end=mid;
                    }else{
                        start=mid+1;
                    }
                }else if(nums[end] > nums[mid]){
                    if(nums[end]<target){
                        end =mid;
                    }else{
                        start=mid+1;
                    }
                }
                //normal binary
            }else{
                if(nums[mid]>target){
                    end = mid;
                }else if(nums[mid]==target){
                    index = mid;
                    break;
                }else{
                    start=mid+1;
                }
            }
            if(start == end){
                if(nums[start] == target){
                    index = start;
                }
                break;
            }
        }
        return index;

    }
};
int main(){
    vector<int> a={4,5,6,7,8,1,2,3};
    int target = 8;
    Solution().search(a,target);
}