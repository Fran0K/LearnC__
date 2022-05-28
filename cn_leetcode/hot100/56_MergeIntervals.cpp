//
// Created by Frank Lin on 2/3/22.
//
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        for(int i =0;i<intervals.size();i++){
            if(ans.size()==0 || ans[ans.size()-1][1]< intervals[i][0]){
                ans.push_back(intervals[i]);
            }else{
                ans[ans.size()-1][1] = max(ans[ans.size()-1][1], intervals[i][1]);
            }
        }
        return ans;

    }
};

int main(){
    vector<vector<int>> intervals={{2,4},{1,3},{3,3},{2,6},{8,10},{15,18}};
    Solution().merge(intervals);
}