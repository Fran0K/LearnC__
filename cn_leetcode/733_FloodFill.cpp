//
// Created by Frank Lin on 19/4/2022.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // int n =image.size();
        // int m = image[0].size();
        int color = image[sr][sc];
        dfs(image, sr, sc,color ,newColor);
        return image;


    }

    void dfs(vector<vector<int>>& image, int i, int j,int color, int newColor){
        if(!(i>=0 && i< image.size() && j>=0 && j<image[0].size())){
            return ;
        }
        if(image[i][j]==newColor){
            return;
        }
        if(image[i][j]==color){
            image[i][j] = newColor;
            dfs(image, i-1, j,color, newColor);
            dfs(image, i+1, j,color, newColor);
            dfs(image, i, j-1,color, newColor);
            dfs(image, i, j+1,color, newColor);
        }
        return;
    }
};

int main(){
    vector<vector<int>>image = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1, sc = 1, newColor = 2;
    Solution().floodFill(image, sr, sc, newColor);
}