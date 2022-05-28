//
// Created by Frank Lin on 23/5/2022.
//
#include "vector"
#include "string"
#include "set"
#include "unordered_map"
using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> st;
        string temp;
        for(int i =0;i<s1.size();i++){
            if(s1[i] == ' ' || i ==(s1.size()-1) ){
                if(i ==(s1.size()-1)){
                    temp+=s1[i];
                }
                st[temp]++;
                temp ="";
            }
            else{
                temp+=s1[i];
            }
        }


        string temp2;
        for(int i =0;i<s2.size();i++){
            if(s2[i] == ' ' || i ==(s2.size()-1) ){
                if(i ==(s2.size()-1)){
                    temp2+=s2[i];
                }
                st[temp2]++;
                temp2 ="";
            }
            else{
                temp2+=s2[i];
            }
        }
        vector<string> ans;
        for(auto p:st){
            if(p.second==1){
                ans.push_back(p.first);
            }
        }


        return ans;
    }
};
int main(){
    string s1="this apple is sweet", s2 = "this apple is sour";
    Solution().uncommonFromSentences(s1,s2);

    //1.c++ 切分字符串？

}