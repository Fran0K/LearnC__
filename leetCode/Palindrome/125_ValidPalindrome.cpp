//
// Created by Frank Lin on 19/5/2022.
//

//给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
//
//说明：本题中，我们将空字符串定义为有效的回文串。
#include "string"

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int r =s.size()-1, l=0;

        while(l<r){
            //判断 l范围有效
            while(l+1 < n && !(isdigit(s[l])|| isalpha(s[l]))){
                l++;
            }
            //判断 r 的范围有效
            while(r>=0 && !(isdigit(s[r])|| isalpha(s[r]))){
                r--;
            }
            //判断l,r 是否已经过头
            //eg".,"就是好例子
            if(l>r){
                break;
            }
            char lc = s[l], rc = s[r];
            //upper to lower
            if(lc >='A' && lc<='Z' ){
                lc = lc-'A'+'a';
            }
            if(rc >='A' && rc<='Z' ){
                rc = rc-'A'+'a';
            }
            if(lc!=rc){
                return false;
            }
            l++;r--;
        }
        return true;


    }
};
int main(){
    string s = ".,";
    Solution().isPalindrome(s);
}