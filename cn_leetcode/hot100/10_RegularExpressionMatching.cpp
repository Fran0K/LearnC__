//
// Created by Frank Lin on 1/3/22.
//
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        return dfs(s,p,0,0);

    }
    bool dfs(string s, string p,int i, int j){
        if(i >= s.size() && j>= p.size()){
            return true;
        }
        if(j >= p.size()){
            return false;
        }

        bool match = ( i<s.size() && ( s[i] == p[j] || p[j] == '.'));

        if(j+1<p.size() && p[i+1] == '*'){
            return dfs(s,p,i,j+2) || ( match && dfs(s, p,i+1,j));
        }

        if(match){
            dfs(s,p,i+1,j+1);
        }
        return false;
    }
};

int main(){
    string s= "aa";
    string p = ".*";
    Solution().isMatch(s,p);
}