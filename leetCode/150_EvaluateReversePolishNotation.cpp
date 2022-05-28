//
// Created by Frank Lin on 1/12/21.
//
#include <vector>
#include <stack>
#include <string>
#include <iostream>
using namespace std;
int evalRPN(vector<string>& tokens) {
    stack<int> st;
    for(string s: tokens){
        if(s!="+" && s!="-" && s!="*" &&s !="/") {
            st.push(stoi(s));
        }
        else {
            int t1 = st.top();
            st.pop();
            if (s == "+") {
                int t = t1+st.top();
                st.pop();
                st.push(t);
            } else if (s == "-") {
                int t = t1-st.top();
                st.pop();
                st.push(t);
            } else if (s == "*") {
                int t = t1*st.top();
                st.pop();
                st.push(t);
            } else if (s == "/"){
                int t = st.top()/t1;
                st.pop();
                st.push(t);
            }
        }
    }
    return st.top();

}
int main(){
    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    int k = evalRPN(tokens);

    cout<< k<<endl;
    return 0;

}