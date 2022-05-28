//
// Created by Frank Lin on 03/03/2022.
//
#include <vector>
#include <set>
using namespace std;

class Solution {

public:
    vector<vector<int>> ans;
    set<vector<int>> st;
    vector<int> temp;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates,target);
        return ans;

    }
    void dfs(vector<int>& candidates, int target){
        if(target == 0){
            sort(temp.begin(), temp.end());
            if(st.find(temp) == st.end()){
                ans.push_back(temp);
                st.insert(temp);
            }
            return;
        }
        else if(target<0){
            return ;
        }else{
            for(int i = 0;i<candidates.size();i++){
                int k = candidates[i];
                temp.push_back(k);
                dfs(candidates,target-k);
                temp.pop_back();
            }
        }
    }
};

int main(){
    vector<int>candidates = {2,3,5};
    int target = 8;
    Solution().combinationSum(candidates,target);
}