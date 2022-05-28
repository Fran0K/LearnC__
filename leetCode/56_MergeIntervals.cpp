//
// Created by Frank Lin on 19/5/2022.
//
#include "vector"

using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int n =intervals.size();
        vector<vector<int>> ans;
        for(int i =0 ;i< n;i++){
            auto t = intervals[i];
            if(ans.empty()|| ans.back()[1]<intervals[i][0]){
                ans.push_back(intervals[i]);
            }else{
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;

    }
};

int main(){
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18},{4,5}};
    Solution().merge(intervals);
}