//
// Created by Frank Lin on 17/5/2022.
//
#include "string"
using namespace std;
class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        int carry =0;
        int n1=num1.size()-1, n2=num2.size()-1;
        while(n1>=0 || n2 >=0|| carry!=0){
            int a = (n1>=0)?num1[n1--]-'0':0;
            int b = (n2>=0)?num2[n2--]-'0':0;
            ans += ((a+b+carry)%10)+'0';
            carry = (a+b+carry)/10;
        }
        reverse(ans.begin(), ans.end());
        return ans;

    }
};

int main(){
    string num1="123";
    string num2="12";
    Solution().addStrings(num1, num2);

}