//
// Created by Frank Lin on 1/3/22.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string s;
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        dfs(n,n);
        return ans;

    }

    void dfs(int left,int right){
        if(right==0 && left==0){
            ans.push_back(s);
            return ;
        }else{
            if(left){
                s.push_back('(');
                dfs(left-1, right);
                s.pop_back();
            }
            if(right>left){
                s.push_back(')');
                dfs(left, right-1);
                s.pop_back();
            }
        }
    }
};

int main(){
    Solution().generateParenthesis(3);
}