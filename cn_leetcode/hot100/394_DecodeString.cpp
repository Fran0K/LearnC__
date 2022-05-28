//
// Created by Frank Lin on 2/3/22.
//

#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        stack<pair<int, string>> st;

        int mulit =0;
        string cur="";
        for(int i =0;i<n;i++){
            if(s[i]>='0' && s[i]<='9' ){
                mulit = s[i]-'0';
                while(s[i+1]>='0' && s[i+1]<='9'){
                    mulit = mulit*10 + s[i+1]-'0';
                    i++;
                }
            }
            else if(isalpha(s[i])){
                cur+=s[i];
            }else if(s[i] == '['){
                st.push(make_pair(mulit, cur));
                mulit = 0;
                cur= "";
            }else if(s[i] == ']'){
                int t = st.top().first;
                string stemp="";
                while(t){
                    stemp += cur;
                    t--;
                }
                cur = st.top().second + stemp;
                st.pop();

            }
        }
        return cur;

    }
};
int main(){
    string s = "3[a]2[bc]";
    Solution().decodeString(s);

}