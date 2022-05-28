//
// Created by Frank Lin on 28/10/21.
//
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    int index = 0;
    int sum =0 ;
    for(int i =numRows; i>0;i--){
        sum += i;
    }
    vector<int> num(sum+1, 1);
    num[0]=0;
    for(int i =1 ;i<=numRows;i++){
        vector<int> temp(i, 1);
        for(int j = 0; j<i;j++){
            index++;
            if(j ==0 || j ==i-1){
                temp[j] = 1;
                num[index] = temp[j];

            }else{
                temp[j] = num[index-i]+num[index-i+1];
                num[index] = temp[j];
            }
        }
        ans.push_back(temp);
    }


    return ans;
}
int main(){
    vector<vector<int>> v1 ;
    v1 = generate(5);
    cout <<"kk";
    return 0;
}
