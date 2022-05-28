//
// Created by Frank Lin on 30/12/21.
//

#include <vector>
#include <string>
using namespace std;
//vector<vector<int>> ans;
//int dp(string word1, int i, string word2, int j){
//    if(i==word1.size() || j== word2.size()){
//        return 0;
//    }
//
//    if(ans[i][j] !=-1){
//        return ans[i][j];
//    }
//    if(word1[i] == word2[j]){
//        ans[i][j]= 1+ dp(word1,i+1,word2, j+1);
//    }else{
//        ans[i][j] = max(dp(word1, i+1, word2,j), dp(word1, i, word2,j+1));
//    }
//    return ans[i][j];
//}

int longestCommonSubsequence(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> memo(m+1 , vector<int>(n+1,0));
    for(int i =1;i<m;i++){
        for(int j =1; j<n; j++){
            if(word1[i-1] == word2[j-1]){
                memo[i][j] = 1+ memo[i-1][j-1];
            }else{
                memo[i][j] = max(memo[i][j-1], memo[i-1][j]);
            }
        }
    }
    return memo[m][n];

}


int main(){
    string word1 = "abc", word2 = "def";
    int k = longestCommonSubsequence(word1, word2);
    return 0;
}