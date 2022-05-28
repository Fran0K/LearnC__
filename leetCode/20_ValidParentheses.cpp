//
// Created by Frank Lin on 13/2/22.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> kk;
        for(int i =0; i<s.size(); i++){
            if(s[i] == '{' || s[i] == '['||s[i] == '('){
                kk.push(s[i]);
            }
            else if(s[i] == '}'){
                char g = kk.top();
                if(g !='{'){
                    return false;
                }
                kk.pop();
            }
            else if(s[i] == ')'){
                char g = kk.top();
                if(g != '('){
                    return false;
                }
                kk.pop();
            }
            else if(s[i] == ']'){
                char g = kk.top();
                if(g != '['){
                    return false;
                }
                kk.pop();
            }
        }
        if(kk.empty()){
            return true;
        }
        return false;

    }
};

int main(){
    string s = "()[{}";
    bool g = Solution().isValid(s);
    cout<<g;
}
