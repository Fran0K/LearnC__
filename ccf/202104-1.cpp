//
// Created by Frank Lin on 7/9/21.
//

//	灰度直方图
//    100
#include <vector>
#include <iostream>
using namespace std;
int main(){
    //int x=4, y=4, k=16, num=0;
    int x, y, k, num;
    cin >>x >>y >>k;

    vector<vector<int>> res;
    for(int i = 0; i<x; i++ ){
        vector<int> temp;
        for(int j = 0 ;j<y; j++){
            cin >> num;
            temp.push_back(num);
            //num++;
        }
        res.push_back(temp);
    }

    vector<int> mp(k,0);
    for(int i = 0; i<x; i++ ){
        for(int j = 0 ;j<y; j++){
            int key = res[i][j];
            mp[key]++;
        }
    }

    for(int i = 0; i<k; i++ ){
        cout<< mp[i]<< " ";
    }
    return 0;

}