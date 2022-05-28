//
// Created by Frank Lin on 23/12/21.
//

#include <iostream>
#include <vector>
using namespace std;
void backtrack(vector<string> board, int row);
bool isVald(vector<string>& board, int row, int col);
vector<vector<string>> ans;

vector<vector<string>> solveNQueens(int n) {
    vector<string> board(n, string(n, '.'));
    backtrack(board,0);
    return ans;
}
void backtrack(vector<string> board, int row){
    if(row == board.size()){
        ans.push_back(board);
        return ;
    }
    int n = board[row].size();
    for(int col = 0 ;col<n; col++){
        if(!isVald(board, row, col)){
            continue;
        }
        board[row][col] ='Q';
        backtrack(board, row+1);
        board[row][col] ='.';
    }
}

bool isVald(vector<string>& board, int row, int col){
    int n = board.size();
    for (int i = 0; i < n; i++) {
        if (board[i][col] == 'Q')
            return false;
    }
    for(int i= row+1, j= col+1; i>=0 && j<n; i--,j++){
        if(board[i][j] =='Q'){return false;}
    }
    for(int i= row-1, j= col-1; i>=0 && j>=0; i--,j--){
        if(board[i][j] =='Q'){return false;}
    }
    return true;
}


int main(){
    solveNQueens(4);
}