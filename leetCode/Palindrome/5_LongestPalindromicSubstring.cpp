//
// Created by Frank Lin on 19/5/2022.
//
//Given a string s, return the longest palindromic substring in s.
//
// 普通方式：
//    一直遍历
//聪明方式：
//  分为奇数与偶数两种，奇数往外扩
#include "string"
#include "iostream"
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n =s.size();
        int ans =0;
        string t;
        for(int i =0;i<n;i++){
            int l =i,r=i;

            while(l>=0 && r<n && s[l]==s[r] ){
                if(r-l+1>ans){
                    ans = r-l+1;
                    t = s.substr(l,ans);
                }
                l--,r++;
            }
            int le = i, re =i+1;
            while(le>=0 && re<n && s[le]==s[re] ){
                if(re-le+1>ans){
                    ans = re-le+1;
                    t = s.substr(le,ans);
                }
                le--,re++;
            }
        }
        return t;
    }
};
int main(){
    string s = "babad";
    string t = Solution().longestPalindrome(s);
    cout<<t;
}