//
// Created by Frank Lin on 23/11/21.
//
#include <string>
#include <iostream>
using namespace std;
int myAtoi(string s) {
    int n = s.size();
    long ans=0;
    int isNag = 1;
    int i = s.find_first_not_of(' ');
    if(s[i] == '-'){
        isNag = -1;
        i++;
    }else if(s[i] == '+'){
        isNag = 1;
        i++;
    }
    else if(s[i]<'0' || s[i]>'9'){
        return 0;
    }
    while(i<n){
        if(s[i]>='0' && s[i]<='9'){
            ans*=10;
            ans+=(s[i]-'0');
        }else{
            return ans;
        }
        if(ans*isNag>=INT_MAX){
            return INT_MAX;
        }
        else if(ans*isNag<=INT_MIN){
            return INT_MIN;
        }
        i++;
    }
    return ans*isNag;
}


int main(){
    string s ="   -42";
    int k = myAtoi(s);
    return 0;
}
