//
// Created by Frank Lin on 7/9/21.
//

//邻域均值
#include <iostream>
#include <vector>
using namespace std;

float cals(vector<vector<int>>& arr, int x, int y,int r, int n){
    int xLow = x-r;
    int xHig = x+r;
    int yLow = y-r;
    int yHig = y+r;

    if (xLow < 0){
        xLow = 0;
    }
    if (yLow < 0){
        yLow = 0;
    }
    if (yHig > n){
        yHig = n-1;
    }
    if (xHig > n){
        xHig = n-1;
    }
    float total = 0.0;
    for(int i = xLow; i <= xHig; i++){
        for(int j = yLow; j <= yHig; j++){
            total += arr[i][j];
        }
    }
    float kk = total / ((1+xHig-xLow)*(1+yHig-yLow));
//    int cmp = (total - arr[x][y])/((1+xHig-xLow)*(1+yHig-yLow)-1);
//    int xs = 6;
    //float kk = total/((1+xHig-xLow)*(1+yHig-yLow));
    return kk;


}

int main(){

    //int n=4, L=16, r=1, t=6, num =0 ;
    int n,L,r,t;
    cin >> n >> L >> r >> t;
    int num;
    int count=0;

    vector<vector<int>> res;
    for(int i = 0; i<n; i++ ){
        vector<int> temp;
        for(int j = 0 ;j<n; j++){
            cin >> num;
            temp.push_back(num);
        }
        res.push_back(temp);
    }

    for(int i =0;i<n;i++){
        for(int j=0; j<n ;j++){
            float bak = cals(res, i, j, r, n);
            if(bak <= t){
                count++;
            }
        }
    }

    cout << count;
    return 0;

}