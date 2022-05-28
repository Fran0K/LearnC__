//
// Created by Frank Lin on 16/11/21.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> temp = vector<int>(26 ,0);
bool isAnagram(string s, string t) {
    string a;
    string b;
    if(s.size()>= t.size()){
        a = s;
        b = t;
    }else{
        a = t;
        b = s;
    }
    for(int i=0; i<a.size();i++){
        int g = a[i]-'a';
        temp[g]++;
    }
    for(int i =0;i<b.size();i++){
        int k = b[i] - 'a';
        temp[k]--;
        if(temp[k]<0){
            return false;
        }
    }
    return true;

}

int main(){
    string s = "ab";
    string ss = "a";
    cout << isAnagram(s,ss);
    return 0;

}