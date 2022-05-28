//
// Created by Frank Lin on 10/04/2022.
//

#include <vector>
#include <iostream>
using namespace std;

void Show(int &pt){
    cout<<pt<<" ";
}

bool cmp(int &t1, int &t2){
    return t1>t2 ? true: false;
}

int main(){

    vector<int> ans = {2,3,4,5,7,1};
    sort(ans.begin(), ans.end());
    for_each(ans.begin(),ans.end(),Show);
    cout<<endl;

    sort(ans.begin(), ans.end(), cmp);
    for_each(ans.begin(),ans.end(),Show);
    cout<<endl;


    return 0;
}