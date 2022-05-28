//
// Created by Frank Lin on 10/11/21.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    vector<string>ans;
    string temp;
    vector<int>exist;
    vector<string> Permutation(string str) {
        if(str == ""){
            return ans;
        }
        vector<int>temp(str.size(),0);
        exist = temp;
        dfs(str, 0);
        return ans;
    }
    void dfs(string str,int index){
        if(temp.size() == str.size()){
            if(ans.size()!=0){
                for(int i = 0 ;i<ans.size();i++){
                    if(ans[i] == temp){
                        return ;
                    }
                }
                ans.push_back(temp);
            }else{
                ans.push_back(temp);

            }
            return ;

        }
        else{
            for(int i =0 ;i<str.size();i++){
                if(exist[i]==1){
                    continue;
                }else{
                    exist[i] =1;
                    temp += str[i];
                    dfs(str, i+1);
                    temp.pop_back();
                    exist[i] = 0;
                }

            }
        }
    }
};
int main(){
    Solution s;
    string str = "aa";
    s.Permutation(str);
    cout<<"hello"<<endl;
    return 0;
}