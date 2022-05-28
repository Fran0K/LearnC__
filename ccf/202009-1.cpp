//
// Created by Frank Lin on 11/9/21.
//

//称检测点查询

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, x, y;
    cin>>n >> x>> y;
    vector<pair<int , int>> ans;

    for(int i = 0 ; i<n; i++){
        int tempX =0, tempY=0;
        cin >> tempX >> tempY;
        int lo = (tempX - x)*(tempX - x) + (tempY - y)*(tempY - y);
        ans.push_back(make_pair(lo, i));

    }
    sort(ans.begin(), ans.end());
    for(int i =0 ;i<3; i++){
        cout<< ans[i].second+1 <<endl;
    }


    return  0 ;
}