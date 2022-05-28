//
// Created by Frank Lin on 23/2/22.
//
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        if (n%2){
            return false;
        }
        for(int i =0 ;i<s.size();i++){
            if(s[i] == '('|| s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }else if(s[i] == ')'){
                if(st.empty()){
                    return false;
                }
                if(st.top()!='('){
                    return false;
                }
                st.pop();
            }else if(s[i] == '}'){
                if(st.empty()){
                    return false;
                }
                if(st.top()!='{'){
                    return false;
                }
                st.pop();
            }else if(s[i] == ']'){
                if(st.empty()){
                    return false;
                }
                if(st.top()!='['){
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();

    }
};

int main(){
    string s = "()[]{}";
    Solution().isValid(s);
}