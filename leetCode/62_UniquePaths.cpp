//
// Created by Frank Lin on 24/1/22.
//

#include<iostream>
#include <vector>
using namespace std;

//wrong solution
//class Solution{
//public:
//    int cc = 0;
//
//    void bfs(int i, int j ,int m,int n){
//        if(i== m-1 && j== n-1){
//            cc++;
//            return;
//        }
//        else{
//            if(i<m-1){
//                bfs(i+1,j,m,n);
//                i--;
//            }
//            if(j<n-1){
//                bfs(i,j+1,m,n);
//                j--;
//            }
//        }
//    }
//    int uniquePaths(int m, int n) {
//        bfs(0,0,m,n);
//        return cc;
//
//    }
//
//};
//

//correct solution
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for(int i =1; i<m;i++){
            for(int j =1; j<n; j++){
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }

};

int main(){
    int k =Solution().uniquePaths(3,2);
    cout<<k;
}