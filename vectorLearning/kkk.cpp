//
// Created by Frank Lin on 16/04/2022.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> antiSpiralOrder(vector<vector<int> >& matrix) {
        // write code here
        int n =matrix.size()-1;
        int m = matrix[0].size()-1;


//        // 旋转
//        for(int i =0 ; i<=n/2;i++){
//            for(int j =0; j<=m/2; j++){
//                int temp = matrix[i][j];
//                matrix[i][j] = matrix[n-i][j];
//                matrix[n-i][j] = matrix[n-i][m-j];
//                matrix[n-i][m-j] = matrix[i][m-j];
//                matrix[i][m-j] = temp;
//            }
//        }
//        for(int i =0 ; i<n;i++){
//            for(int j =0; j<m; j++){
//                cout<< matrix[i][j]<<" "<<endl;
//            }
//            cout<<endl;
//        }
//
//        // 输出
//        vector<int> ans;
//        return ans;
    }
};



int main(){
    vector<vector<int>> ma = {{1,2,3},{4,5,6},{7,8,9}};
    Solution().antiSpiralOrder(ma);
    return 0;
}