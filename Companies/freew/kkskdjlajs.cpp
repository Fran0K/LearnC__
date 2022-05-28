//
// Created by Frank Lin on 16/04/2022.
//
#include <iostream>
#include <vector>
using namespace std;


vector<int> antiSpiralOrder(vector<vector<int> >& matrix){
    int n =matrix.size()-1;
    int m = matrix[0].size()-1;


    cout<<n<<endl;
}
int main(){
    vector<vector<int>> ma{{1,2,3},{4,5,6},{7,8,9}};
    antiSpiralOrder(ma);
    return 0;
}