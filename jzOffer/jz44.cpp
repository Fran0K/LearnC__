//
// Created by Frank Lin on 27/9/21.
//
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
string ReverseSentence(string str) {
    string s ="";
    queue<char> q;
    for(int i=str.size()-1;i>=0; i--){
        if(str.at(i) != ' '){
            q.push(str.at(i));
        }else{
            string temp = "";
            while(!q.empty()){
                char s = q.back();
                //q.pop();
                temp += s;

            }
            temp = temp+' ';
            s+=temp;
        }
    }
    return s;
}

int main(){
    string s = "nowcoder. a am I";
    ReverseSentence(s);
}