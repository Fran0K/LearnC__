//
// Created by Frank Lin on 30/03/2022.
//
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int count =0;
        for(int i =0;i<n;i++){
            for(int j =0; j<m;j++){
                if(grid[i][j] == 1){
                    count++;
                }
                else if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        int mn =0;
        while(count>=0 && !q.empty()){
            int qs = q.size();
            mn++;
            for(int i =0; i<qs;i++){
                auto iter = q.front();
                int x = iter.first;
                int y =iter.second;
                q.pop();
                if(check(grid,x-1,y)){
                    count--;
                    q.push({x-1,y});
                    grid[x-1][y]=2;
                }
                if(check(grid,x+1,y)){
                    count--;
                    q.push({x+1,y});
                    grid[x+1][y]=2;
                }
                if(check(grid,x,y-1)){
                    count--;
                    q.push({x,y-1});
                    grid[x][y-1]=2;
                }
                if(check(grid,x,y+1)){
                    count--;
                    q.push({x,y+1});
                    grid[x][y+1]=2;
                }
            }
        }
        return count>0? -1:mn;
    }

    bool check(vector<vector<int>>& grid, int i, int j){
        if(!( i>=0 && i<grid.size() && j>=0 && j< grid.size())){
            return false;
        }
        if(grid[i][j] == 2 || grid[i][j]==0){
            return false;
        }
        return true;
    }

};

int main(){
    vector<vector<int>> n = {{2,1,1},{1,1,0},{0,1,1}};
    Solution().orangesRotting(n);
}