//
// Created by Frank Lin on 23/2/22.
//
#include <string>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int j = s.size()-1;
        if(s[j]==' '){
            while(s[j]==' '){
                j--;
            };
        }
        int end =j;
        while(s[j]!=' '&& j>=0){
            j--;
        }
        return end-j;

    }
};

int main(){
    string s = "a";
    Solution().lengthOfLastWord(s);
}