//
// Created by Frank Lin on 17/12/21.
//
#include <iostream>
#include <vector>
using namespace std;
int mins (int a, int b, int c){
    return min(a, min(b,c));
}

int dp(vector<vector<int>>& matrix ,vector<vector<int>>& memo, int i, int j){
    if(i <0 || j<0 || i>=matrix.size() || j>=matrix.size()){
        return 1000;
    }

    if(i ==0 ){
        return matrix[i][j];
    }
    if(memo[i][j] != 6666){
        return memo[i][j];

    }

    memo[i][j] = matrix[i][j] + mins(dp(matrix, memo, i-1, j-1), dp(matrix,memo, i-1, j),dp(matrix,memo, i-1, j+1));
    return memo[i][j];

}


int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int res  = INT_MAX;
    vector<vector<int>> memo(n, vector<int>(n,6666));
    for(int i = 0; i<n; i++){
        res = min(res, dp(matrix ,memo,n-1, i));
    }
    return res;

}

int main(){
    vector<vector<int>> v ={{2,1,3},{6,5,4},{7,8,9}};
    minFallingPathSum(v);
    for(auto elem: v){

    }

}