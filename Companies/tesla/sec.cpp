//
// Created by Frank Lin on 17/4/2022.
//
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<int> &a){
    int n = a.size();
    unordered_map<int,int>mp;
    int l=0,r=0;
    int count =0;
    int mi = INT_MIN;
    while(r<n){
        // to right
        int temp = a[r];
        if(!mp.count(temp)){
            count++;
        }
        mp[temp]++;
        while(count>2){
            int x = a[l];
            mp[x]--;
            if(!mp.count(x)){
                count--;
            }
            l++;
        }
        mi = max(mi, r+1-l);
        r++;
    }
    return mi;

}

int main(){
    vector<int> a={1,2,3,2};
    solution(a);

}