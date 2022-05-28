//
// Created by Frank Lin on 17/9/21.
//
#include <iostream>
using namespace std;

int StrToInt(string str) {
    if(str.size()==0){
        return 0 ;
    }
    int n = str.size();
    int time = 1;
    int ans=0;
    while(n--){
        char temp = str[n];
        if (temp == '+'){
            continue;
        }
        if(temp - '0' >=0 && temp - '9'<= 0){
            ans = ans+ (temp-'0')*time;
            time = time * 10;
        }else{
            return 0;
        }
    }
    return ans;
}
int main(){
    string s = "+2147483647";
    int k = StrToInt(s);
}