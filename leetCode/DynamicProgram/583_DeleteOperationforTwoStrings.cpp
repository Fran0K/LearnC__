//
// Created by Frank Lin on 29/12/21.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<vector<int>> ans;
int dp(string word1, int i, string word2, int j){
    if(i==word1.size() || j== word2.size()){
        return 0;
    }

    if(ans[i][j] !=-1){
        return ans[i][j];
    }
    if(word1[i] == word2[j]){
        ans[i][j]= 1+ dp(word1,i+1,word2, j+1);
    }else{
        ans[i][j] = max(dp(word1, i+1, word2,j), dp(word1, i, word2,j+1));
    }
    return ans[i][j];
}

int minDistance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();
    ans.resize(n, vector<int>(m,-1));
    int com = dp(word1, 0, word2, 0);
    return m+n-2*com;

}


int main(){
    string word1 = "dinitrophenylhydrazine", word2 = "acetylphenylhydrazine";
    int k = minDistance(word1, word2);
    return 0;
}