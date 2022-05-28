//
// Created by Frank Lin on 07/03/2022.
//

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    unordered_map<char,vector<char>> mp={
            {'2',{'a','b','c'}},
            {'3',{'d','e','f'}},
            {'4',{'g','h','i'}} ,
            {'5',{'j','k','l'}} ,
            {'6',{'m','n','o'}} ,
            {'7',{'p','q','r','s'}} ,
            {'8',{'t','u','v'}} ,
            {'9',{'w','x','y','z'}}
    };
    vector<string> ans;
    string temp;

    vector<string> letterCombinations(string digits) {
        dfs(digits,0);
        return ans;
    }

    void dfs(string digits, int start){
        if(temp.size() == digits.size()){
            ans.push_back(temp);
            return ;
        }else{
            vector<char> kk = mp[digits[start]];
            for(int j =0;j<kk.size();j++){
                temp+=kk[j];
                dfs(digits,start+1);
                temp.pop_back();
            }

//            for(int i= start; i<digits.size() ; i++){
//                vector<char> kk = mp[digits[i]];
//                for(int j =cstart;j<kk.size();j++){
//                    temp+=kk[j];
//                    dfs(digits,i+1,j);
//                    temp.pop_back();
//                }
//                dfs(digits,i+1,0);
//            }
        }
    }
};

int main(){
    string s = "";
    Solution().letterCombinations(s);
}