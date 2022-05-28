//
// Created by Frank Lin on 17/11/21.
//
#include <vector>
#include <iostream>
#include <set>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
    if(nums.size()<3){
        vector<vector<int>> gg;
        return gg;
    }
    set<vector<int>>kk;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for(int i =0;i<n ;i++){
        int target = -nums[i];
        int j=i+1;
        int end = n-1;
        while(j<end){
            int sum = nums[j]+nums[end];
            if(sum==target){
                vector<int> temp;
                temp = {nums[i], nums[j],nums[end]};
                kk.insert(temp);
                while(j<end && nums[j] == nums[i])j++;
                while(j<end && nums[end] == nums[j])end--;
                
            }else if(sum>target){
                end--;
            }else{
                j++;
            }
        }
    }
    vector<vector<int>> ans(kk.begin(),kk.end());
    return ans;

}

int main(){
    vector<int> k;
    vector<vector<int>> a;
    k = {-1,0,1,2,-1,-4};
    a = threeSum(k);
    return 0;
}