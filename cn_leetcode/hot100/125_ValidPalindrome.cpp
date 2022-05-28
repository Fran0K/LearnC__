//
// Created by Frank Lin on 27/2/22.
//
using namespace std;

#include <string>
class Solution {
public:
    bool isPalindrome(string s) {
        int i =0, j=s.size()-1;
        while(i<j){
            while(!isalpha(s[i]) && i<j){
                i++;
            }
            while(!isalpha(s[j]) && i<j){
                j--;
            }
            if(i>j){
                break;
            }
            if(tolower(s[i])!=tolower(s[j])){
                return false;
            }
            i++,j--;
        }
        return true;

    }
};

int main(){
    string s="0P";
    Solution().isPalindrome(s);
}
