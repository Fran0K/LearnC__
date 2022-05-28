//
// Created by Frank Lin on 07/03/2022.
//
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n =matrix.size();
        int colEnd = 0;
        int rowEnd =0;

        for(int i =0;i<(n/2);i++){
            for(int j =0; j<(n+1)/2;j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-j][n-1-i];
                matrix[n-1-j][n-1-i] = matrix[j][n-1-i];
                matrix[j][n-1-i] = temp;
            }
        }
        int ksds =0;
    }
};

int main(){
    vector<vector<int>> matrix =
            {{1,2,3},{4,5,6},{7,8,9}};
    Solution().rotate(matrix);
}
