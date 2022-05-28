//
// Created by Frank Lin on 24/5/2022.
//
#include "vector"
#include "iostream"

using namespace std;
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        merge(nums, 0, n-1);
        for(auto p :nums){
            cout<< p<<" ";
        }
        return n;

    }
    void merge(vector<int>& nums, int start ,int end){
        if(start<end){
            int mid = start + (end-start)/2;
            merge(nums, start, mid);
            merge(nums, mid+1, end);
            mergeSort(nums, start,mid,end);
        }
    }

    void mergeSort(vector<int>& nums, int start ,int mid ,int end){

        vector<int> temp;
        int i=start,j = mid+1;
        while(i<=mid && j<=end){
            if(nums[i]<nums[j]){
                temp.push_back(nums[i]);
                i++;
            }else{
                temp.push_back(nums[j]);
                j++;
            }

        }
        //j没完
        while(j<=end){
            temp.push_back(nums[j]);
            j++;
        }
        //i没完
        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }

        for(int k = 0 ;k<temp.size();k++){
            nums[k+start] = temp[k];
        }

    }

};

int main(){
    vector<int>nums={7,5,6,4};
    Solution().reversePairs(nums);
}