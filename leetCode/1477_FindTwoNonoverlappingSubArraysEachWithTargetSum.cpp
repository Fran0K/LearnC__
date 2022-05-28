//
// Created by Frank Lin on 13/5/2022.
//
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        map<int,vector<int>>mp;
        int n = arr.size();
        for(int i =0;i<n;i++){
            int ts = arr[i];
            int j=i;
            while(j<n){
                if(ts>target){
                    break;
                }
                if(ts == target){
                    mp[target].push_back(j-i+1);
                }
                j++;
                ts+=arr[j];
            }
        }
        if(!mp.count(target)||mp[target].size()<2){
            return -1;
        }
        sort(mp[target].begin(),mp[target].end());
        int ans=0;
        for(int i=0;i<2;i++){
            ans+=mp[target][i];
        }
        return ans;
    }
};

int main(){
    vector<int>arr = {4,3,2,6,2,3,4};
    int target = 6;
    Solution().minSumOfLengths(arr, target);
}