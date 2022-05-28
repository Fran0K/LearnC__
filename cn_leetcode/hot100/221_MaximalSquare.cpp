//
// Created by Frank Lin on 2/3/22.
//
#include <vector>
using namespace std;
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m,0));
        for(int i =0; i<m;i++){
            dp[0][i] = matrix[0][i]-'0';
        }
        for(int j =0;j<n;j++){
            dp[j][0] = matrix[j][0]-'0';
        }
        for(int i =1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j] =='0'){
                    dp[i][j] = 0;
                }else{
                    dp[i][j] = min(dp[i][j-1],min(dp[i-1][j-1], dp[i-1][j]))+1;
                }
            }
        }
        return dp[n-1][m-1];
    }
};

int main(){
    vector<vector<char>> matrix={
            {'1','0','1','0','0'},
            {'1','0','1','1','1'},
            {'1','1','1','1','1'},
            {'1','0','0','1','0'}
    };
    Solution().maximalSquare(matrix);

}