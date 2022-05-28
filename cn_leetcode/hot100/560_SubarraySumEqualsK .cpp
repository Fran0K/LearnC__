//
// Created by Frank Lin on 06/03/2022.
//
#include <vector>
#include <map>
using namespace std;

//class Solution {
//public:
//    int subarraySum(vector<int>& nums, int k) {
//        //前缀和
//        int n = nums.size();
//        vector<int> prefSum(n,0);
//        int count =0;
//        for(int i = 0;i<n;i++){
//            if(i==0){
//                prefSum[i] = nums[i];
//            }else{
//                prefSum[i] =prefSum[i-1]+nums[i];
//            }
//        }
//        for(int i=0;i<n;i++){
//            if(i==0) {
//                if (prefSum[i] == k) {
//                    count++;
//                }
//            }else{
//                for(int j=i-1;j>=0;j--){
//                    if((prefSum[i] - prefSum[j] == k) || prefSum[i] ==k){
//                        count++;
//
//                    }
//
//                }
//            }
//        }
//        return count;
//
//    }
//};
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //前缀和
        int n = nums.size();
        vector<int> prefSum(n+1,0);
        map<int, int>mp;
        int count =0;
        for(int i = 0;i<n;i++){
            if(i==0){
                prefSum[i] =nums[i];
            }else{
                prefSum[i] =prefSum[i-1]+nums[i];
            }
            if(mp.count(prefSum[i])){
                mp[prefSum[i]]++;
            }else{
                mp[prefSum[i]]=1;
            }

        }
        for(int i=0;i<n;i++){
            if(mp.count(k - prefSum[i])){
                count+=mp[k - prefSum[i]];
            }
        }
        return count;
    }
};
int main(){
    vector<int>nums = {1,1,1};
    int k = 2;
    Solution().subarraySum(nums,k);
}
