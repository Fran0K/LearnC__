//
// Created by Frank Lin on 27/5/2022.
//
#include "vector"
#include "string"
#include "stack"
#include "set"
#include "iostream"
using namespace std;

class Solution {
public:

    set<string>st;
    int len;
    int max_pair;
    vector<string> removeInvalidParentheses(string s) {
        int n =s.size();
        int l = 0, r = 0;   // 要删除的左右括号个数
        int totl = 0, totr = 0; // 总共的左右括号个数，用于计算最多可以拥有的括号数
        // 计算删除的左右括号
        for (char ch : s) {
            if (ch == '(') {
                ++totl, ++l;    // 对于左括号无脑加，只有右括号可以消除左括号
            } else if (ch == ')') {
                ++totr;
                if (l > 0) --l;
                else ++r;   // 没有能跟这个右括号构成合法括号的左括号，只能删除
            }
        }
        // 计算可能获得的最多的括号对数量，但可能是达不到要求的，比如对于")("，max_score是1，但只能全删了
        max_pair = min(totl, totr);
        // 计算正确的答案字符串长度
        len = n - l - r;

        //dfs处理
        string cur;
        dfs(s, cur,0,l,r,0);

        vector<string>ans(st.begin(), st.end());
        return ans;
    }


    void dfs(string s, string &cur,int idx, int l, int r, int score){
        cout<<cur<<endl;
        if (cur.size() > len || l < 0 || r < 0 || score < 0 || score > max_pair){
            return;
        }
        if(r==0 && l==0 && score==0 && cur.size()==len){
            st.insert(cur);
            return;
        }
        if (idx == s.size()) return;
        if(s[idx]=='('){
            //keep
            cur.push_back('(');
            dfs(s,cur,idx+1,l,r,score+1);
            //cut
            cur.pop_back();
            dfs(s,cur,idx+1,l-1,r,score);

        }else if(s[idx]==')'){
            //keep
            //keep了就代表多一个对，所以score要+1；
            cur.push_back(')');
            dfs(s,cur,idx+1,l,r,score-1);
            //cut
            cur.pop_back();
            dfs(s,cur,idx+1,l,r-1,score);

        }else{
            cur.push_back(s[idx]);
            dfs(s,cur,idx+1,l,r,score);
            cur.pop_back();
        }
    }
};

int main(){
    string s = "()())()";
    Solution().removeInvalidParentheses(s);

}