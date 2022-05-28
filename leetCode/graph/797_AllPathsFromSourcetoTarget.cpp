//
// Created by Frank Lin on 17/12/21.
//
#include <iostream>
#include <vector>
#include <deque>
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        if(graph.size() == 0){
            return graph
        }
        find(graph);
        return ans;

    }

    void bfs(vector<vector<int>>& graph){
        int n = graph.size();
        int m = graph[0].size();
        for(int i = 0; i<n;i++){

        }
    }
};

int main(){

}