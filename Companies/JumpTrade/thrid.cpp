//
// Created by Frank Lin on 25/4/2022.
//
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

string check(string s){
    string f ="FALSE";
    string y ="YES";
    if(s =="123321"){
        return y;
    }else if(s == "12621"){
        return y;
    } else if(s == "14331"||s == "13341"){
        return y;
    }else if(s == "1101"){
        return y;
    }else if (s =="111"){
        return y;
    }else if(s=="12"){
        return y;
    }
    return f;
}

bool cmp(pair<int ,int> &a, pair<int ,int> &b){
    return a.first>=b.first;
}

string solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)

    unordered_map<int,int>mp;
    vector<pair<int,int>> temp;
    for(auto num:A){
        mp[num]++;
    }

    for(auto t: mp){
        temp.emplace_back(make_pair(t.first,t.second));
    }
    sort(temp.begin(), temp.end(), cmp);
    string s;
    int n = temp.size()
    for(int i=0;i<;i++){
        s+=('0'+temp[i].second);
    }
    return check(s);

}

int main(){
    vector<int>A = {4, 3, 3, 4, 1, 2, 2, 3, 6, 5, 4, 5};
    solution(A);

}