//
// Created by Frank Lin on 06/03/2022.
//

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int count=0;

        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j] == '1'){
                    dfs(grid,i,j);
                    count++;
                }
            }
        }
        return count;

    }

    void dfs(vector<vector<char>>& grid, int i, int j){
        if(!(i>=0 && i<grid.size() && j>=0 && j<grid[0].size())){
            return ;
        }
        if(grid[i][j]!='1'){
            return ;
        }
        grid[i][j]='2';
        dfs(grid,i-1,j);
        dfs(grid,i+1,j);
        dfs(grid,i,j-1);
        dfs(grid,i,j+1);

    }
};

int main(){
    vector<vector<char>> grid = {
    {'1','1','1','1','0'},
    {'1','1','0','1','0'},
    {'1','1','0','0','0'},
    {'0','0','0','0','0'}};
    Solution().numIslands(grid);
}