//
// Created by Frank Lin on 04/03/2022.
//
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i =0;
        int j=i+1;
        int mx =1;
        while(i<n){
            while(j<n && s[i]!=s[j]){
                j++;
            }
            mx = max(j-i,mx);
            i++;
            if(i==j){
                j++;
            }
        }
        return mx;

    }
};

int main(){
    string s = "abcabcbb";
    Solution().lengthOfLongestSubstring(s);
}