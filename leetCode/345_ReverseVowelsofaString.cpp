//
// Created by Frank Lin on 24/11/21.
//
#include <string>
#include <iostream>
using namespace std;

bool isVow(string s, int index){
    if(s[index] == 'a' ||
    s[index] == 'e'||
    s[index] == 'i'||
    s[index] == 'o'||
    s[index] == 'u'||
    s[index] == 'A'||
    s[index] == 'E'||
    s[index] == 'I'||
    s[index] == 'O'||
    s[index] == 'U'){
        return true;
    }return false;
}
string exch(string s, int front ,int end){
    char temp = s[front];
    s[front] = s[end];
    s[end] = temp;
    return s;
}
string reverseVowels(string s) {

    int n = s.size()-1;
    int front = 0;
    int end = s.size()-1;
    while(front <end){
        while(!isVow(s,front) && front<n ){
            front++;
        }
        while(!isVow(s,end) && end>0 ){
            end--;
        }if(front<end && isalpha(s[front]) && isalpha(s[end]) ){

            s = exch(s, front ,end);
            front++;
            end--;
        }

    }
    return s;
}

int main(){
    string s = "1->2->3";
    //string k =reverseVowels(s);
    s.pop_back();
    s.pop_back();
    return 0;
}