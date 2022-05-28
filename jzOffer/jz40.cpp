//
// Created by Frank Lin on 28/8/21.
//
#include <iostream>
#include <map>      // pair
#include <string>       // string
#include <vector>
using namespace std;


vector<int> FindNumsAppearOnce(vector<int>& array) {
    // write code here
    map<int, int> mp;
    vector<int> res;
    for(vector<int>::iterator it = array.begin();it!= array.end();it++){
        map<int, int>::iterator iter = mp.find(*it);
        if(iter != mp.end()){
            iter->second++;
        }
        else{
            mp.insert(pair<int, int>(*it, 1));
        }
    }
    for(auto iter = mp.begin(); iter!= mp.end(); iter++){
        if(iter->second == 1){
            res.push_back(iter->first);
        }
    }
    return res;
}

int main(){
    vector<int> v ;
    v.push_back(1);
    v.push_back(4);
    v.push_back(1);
    v.push_back(6);
    vector<int> arr2;
    arr2 = FindNumsAppearOnce(v);
    return 0;
}