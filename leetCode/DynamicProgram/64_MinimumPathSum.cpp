//
// Created by Frank Lin on 15/12/21.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int> > sum(m, vector<int>(n, 0));
        sum[0][0] = grid[0][0];
        for(int i = 1; i<m;i++){
            sum[i][0] = sum[i-1][0]+grid[i][0];
        }
        for(int j =1; j<n;j++){
            sum[0][j] = sum[0][j-1]+grid[0][j];
        }
        for(int i =1; i<m;i++){
            for(int j =1; j<n;j++){
                sum[i][j] = min(sum[i-1][j], sum[i][j-1])+grid[i][j];
            }
        }
        return sum[m-1][n-1];
    }

};

int main(){
    vector<int>v = {1,2,3};
    vector<int>v1 = {4,5,6};
    vector<vector<int>> grid;
    grid.push_back(v);
    grid.push_back(v1);
    Solution s;
    s.minPathSum(grid);
    return  0 ;

}
