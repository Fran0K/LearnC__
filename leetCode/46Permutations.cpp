//
// Created by Frank Lin on 9/11/21.
//


#include <iostream>
#include <cmath>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    vector<vector<int>> ans;
    set<int> exist;
    vector<int> temp;
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums, temp);
        return ans;
    }
    bool isExist(int num){
        auto it = exist.find(num);
        if(it!= exist.end()){
            return true;
        } else{
            return false;
        }

    }

    void dfs(vector<int>& nums, vector<int>& temp){
        cout<<"dfs :[ ";
        for(int i=0;i<temp.size();i++){
            cout<<temp[i]<<" ";
        }
        cout<<"] "<<endl;
        if(exist.size() == nums.size()){
            ans.push_back(temp);
            cout<<endl;
            return ;

        }else{
            for(int i =0; i<nums.size();i++){
                int num = nums[i];
                if(isExist(num)){
                    continue;
                }else{
                    temp.push_back(num);
                    exist.insert(num);
                    dfs(nums, temp);
                    exist.erase(num);
                    temp.pop_back();
                }

            }

        }
    }
};

int main(){
    Solution s;
    int t[]= {1,2,3};
    vector<int>v(t, t+sizeof(t)/ sizeof(int));
    s.permute(v);
    cout<<"hello"<<endl;
    return 0;
}