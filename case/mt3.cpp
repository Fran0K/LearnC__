//
// Created by Frank Lin on 02/04/2022.
//
#include <vector>
#include <iostream>
using namespace std;
class Solution{
public:
    int count =0;
    string tt;
    int test(string s, string p){
        dfs(s,p,0,0);
        return count;

    }
    void dfs(string s, string p, int start,int cur){
        if(tt.size()!=0 && tt[tt.size()]!= p[tt.size()]){
            return;
        }

        if(tt.size() == p.size()){
            count++;
            return;
        }

        for(int i =start;i<s.size();i++){
            tt+=p[start];
            dfs(s,p,start+1,cur+1);
            tt.pop_back();
        }

    }
};

int main(){
    string s = "acac";
    string p = "ac";

    Solution().test(s,p);
}
