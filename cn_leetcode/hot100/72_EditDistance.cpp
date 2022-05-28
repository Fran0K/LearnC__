//
// Created by Frank Lin on 09/03/2022.
//

#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])+1;
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }

            }

        }
        return n>m?n-dp[n][m]:m-dp[n][m];

    }
};

int main(){
    string word1="intention";
    string word2="execution";
    Solution().minDistance(word1, word2);
}