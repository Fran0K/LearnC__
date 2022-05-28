//
// Created by Frank Lin on 11/03/2022.
//
#include <vector>
#include <iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
};

class Solution {
public:
    vector<int> antiSpiralOrder(vector<vector<int>>& matrix) {
        // write code here
        int n =matrix.size();
        int m = matrix[0].size();

        // 输出
        vector<int> ans;
        int l =0, r =m-1;
        int u =0, d= n-1;
        int count =0;
        int sum = n*m;
        while(count<=sum){
            //l->r
            for(int i =l; i<=r;i++){
                ans.push_back(matrix[d][i]);
                count++;
                if(count>=sum){
                    break;
                }
            }
            d--;

            for(int i =d ;i>=u;i--){
                ans.push_back(matrix[i][r]);
                count++;
                if(count>=sum){
                    break;
                }
            }
            r--;

            for(int i =r ;i>=l;i--){
                ans.push_back(matrix[u][i]);
                count++;
                if(count>=sum){
                    break;
                }
            }
            u++;

            for(int i =u ;i<=d;i++){
                ans.push_back(matrix[i][l]);
                count++;
                if(count>=sum){
                    break;
                }
            }
            l++;

        }
        for(int i =0;i<ans.size();i++){
            cout<<ans[i];
        }
        return ans;
    }
};
int main(){
    vector<vector<int>> num ={{1,2,3},{4,5,6},{7,8,9}};

    Solution().antiSpiralOrder(num);





}