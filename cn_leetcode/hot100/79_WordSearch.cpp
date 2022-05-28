//
// Created by Frank Lin on 08/03/2022.
//

#include <vector>
using namespace std;
class Solution {
public:
    string tt;
    bool isExist =false;
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>>t(m,vector<int>(n,0));
        for(int i =0; i<m;i++){
            for(int j =0; j<n;j++){
                if(board[i][j] == word[0]){
                    dfs(board,i,j,word,t);
                }
                if(isExist==true){
                    break;
                }
            }
        }
        return isExist;

    }
    void dfs(vector<vector<char>>& board, int i, int j, string word, vector<vector<int>>&t){
        if(!(i>=0 &&i<board.size() && j>=0 && j<board[0].size())){
            return ;
        }
        tt+=board[i][j];
        if(tt[tt.size()-1]==word[tt.size()-1] && t[i][j]==0){
            t[i][j]=1;
            if(tt.size()==word.size()){
                isExist =true;
                return;
            }
            dfs(board,i,j+1,word,t);
            dfs(board,i,j-1,word,t);
            dfs(board,i+1,j,word,t);
            dfs(board,i-1,j,word,t);
        }
        tt.pop_back();
        t[i][j]=0;

        return ;
    }
};

int main(){
//    vector<int> t={{"A","B","C","E"},{"S","F","C","S"},{"A","D","E","E"}};
    vector<int> t={{"A","B","C","E"},{"S","F","C","S"},{"A","D","E","E"}};
    string word = "SEE";
    Solution().exist(t,word);
}