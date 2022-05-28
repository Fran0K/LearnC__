//
// Created by Frank Lin on 30/11/21.
//
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n =temperatures.size();
    vector<int> ans(n, 0);
    stack<int> s;

    for(int i =n-1 ;i>=0; i--){

        while(!s.empty() && temperatures[s.top()] <= temperatures[i]){
            s.pop();
        }

        if(!s.empty()){
            ans[i]=s.top()-i;
        }
        s.push(i);
    }
    return ans;
}
int main(){
    vector<int> kk  = {73, 74, 75, 71, 69, 72, 76, 73} ;
    vector<int> ans;

    dailyTemperatures(kk);
    return 0;
}