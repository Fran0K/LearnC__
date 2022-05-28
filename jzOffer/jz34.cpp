//
// Created by Frank Lin on 19/8/21.
//
#include <iostream>
#include <vector>
using namespace std;
int FirstNotRepeatingChar(string str) {
    vector<int> count(52, 0);
    int temp =0;
    for (int i =0; i< str.size(); i++){
        int bias = char(str[i]) - 'A';
        count[bias]++;
    }
    for (int i =0; i< str.size(); i++){
        int k = char(str[i]) - 'A';
        if(count[k]== 1){
            return i;
        }
    }
    return -1;

}

int main(){
    string s="sxvLtVYEiFzvcmJOzEKCWfUeSsHOpCbLQYiiFjDGvlYaOyEuhiSShuzg";
    int ret =FirstNotRepeatingChar(s);
    cout<<"ret: "<<ret<<endl;
    return 0;
}

