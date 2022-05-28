//
// Created by Frank Lin on 24/2/22.
//
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i =0;i<n;i++){
            dp[0][i]=1;
        }
        for(int j=0;j<m;j++){
            dp[j][0]=1;
        }
        for(int i =1; i<n; i++){
            for(int j= 1; j<m; j++){
                dp[j][i] = dp[j-1][i]+dp[j][i-1];
            }
        }

        return dp[m-1][n-1];



    }
};

int main(){
    Solution().uniquePaths(3,7);
}
