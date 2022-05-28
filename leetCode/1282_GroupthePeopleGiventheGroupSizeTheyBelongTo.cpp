//
// Created by Frank Lin on 12/5/2022.
//
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();

        unordered_map<int, queue<int>>mp;
        for(int i =0; i<n;i++){
            mp[groupSizes[i]].push(i);
        }

        vector<vector<int>> ans;

        for(auto p : mp){
            if(p.first>=p.second.size()){
                vector<int> temp;
                while(!p.second.empty()){
                    temp.push_back(p.second.front());
                    p.second.pop();
                }
                ans.push_back(temp);
            }else{
                int count = p.second.size()/p.first;
                for(int i =0;i<count;i++){
                    vector<int> temp;
                    for(int j =0;j<p.first;j++){
                        temp.push_back(p.second.front());
                        p.second.pop();
                    }
                    ans.push_back(temp);
                }

            }
        }

        return ans;
    }
};
int main(){
    vector<int>groupSizes ={ 3,3,3,3,3,1,3};
    Solution().groupThePeople(groupSizes);
}