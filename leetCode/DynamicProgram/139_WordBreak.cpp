//
// Created by Frank Lin on 15/12/21.
//
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    if(wordDict.size() == 0)return false;
    unordered_set<string> dic(wordDict.begin(), wordDict.end());
    vector<bool> ans(s.size()+1, false);
    ans[0] = true;

    for(int i = 1 ;i<=s.size(); i++){
        for(int j =i-1; j>=0; j--){
            if(ans[j])
            {
                string word = s.substr(j,i-j);
                if(dic.find(word)!= dic.end())
                {
                    ans[i]=true;
                    break; //next i
                }
            }
        }
    }
    return ans[s.size()];
}

int main(){
    string s = "applepenapple";
    vector<string> wordDict = {"apple","pen"};
    wordBreak(s,wordDict);
    return 0;
}