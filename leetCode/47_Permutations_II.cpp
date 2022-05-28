//
// Created by Frank Lin on 10/11/21.
//


#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    vector<int> indx;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> kk(nums.size(), 0);
        indx = kk;
        dfs(nums,0);
        return ans;

    }
    void dfs(vector<int>& nums, int index){
        if(temp.size() == nums.size()){
            if(ans.size()!=0){
                for(int i =ans.size()-1 ;i>=0;i--){
                    if(ans[i] == temp){
                        return;
                    }
                }
                ans.push_back(temp);
            }
            else{
                ans.push_back(temp);
            }

            return;
        }else{
            for(int i =0;i<nums.size(); i++){
                if(indx[i] == 1){
                    continue;
                }else{
                    temp.push_back(nums[i]);
                    indx[i]=1;
                    dfs(nums, i+1);
                    temp.pop_back();
                    indx[i]=0;
                }

            }
        }
    }
};


int main(){
    Solution s;
    int t[]= {1,1,2};
    vector<int>v(t, t+sizeof(t)/ sizeof(int));
    s.permuteUnique(v);
    cout<<"hello"<<endl;
    return 0;
}