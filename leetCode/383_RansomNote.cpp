//
// Created by Frank Lin on 16/11/21.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

vector<int>temp(26,0);
bool canConstruct(string ransomNote, string magazine) {
    for(int i =0 ;i<magazine.size(); i++){
        int a = magazine[i] -'a';
        temp[a]= temp[a]+1;
    }
    for(int j = 0; j<ransomNote.size(); j++){
        int k = ransomNote[j]-'a';
        temp[k]--;
        if(temp[k]<0){
            return false;
        }
    }
    return true;

}

int main(){
    unordered_set<int> container;
    container.insert(1);
    container.insert(2);
    int element =1;
    const bool is_in = container.find(element) != container.end();
    cout<< is_in;
    //canConstruct(s,ss);
    return 0;

}