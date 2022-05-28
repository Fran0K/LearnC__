//
// Created by Frank Lin on 17/9/21.
//

#include <iostream>
#include <vector>
using namespace std;
vector<int> printMatrix(vector<vector<int> > matrix) {
    int top = 0;
    int button = matrix.size()-1;
    cout<<button<<endl;
    int left = 0;
    int right = matrix[0].size()-1;
    cout<<right<<endl;
    vector<int> ans;
    int count = matrix[0].size()*matrix.size();
    int temp = 1;
    while(temp <= count){
        for(int i = left; i<=right ;i++){
            if(temp > count)break;
            ans.push_back(matrix[top][i]);
            temp++;

        }
        for(int i = top+1; i<= button; i++){
            if(temp > count)break;
            ans.push_back(matrix[i][right]);
            temp++;

        }
        for(int i = right-1; i >= left; i--){
            if(temp > count)break;
            ans.push_back(matrix[button][i]);
            temp++;

        }
        top++;
        for(int i = button -1; i >= top; i--){
            if(temp > count)break;
            ans.push_back(matrix[i][left]);
            temp++;
        }
        left++;
        right--;
        button--;
    }
    return ans;
}

int main(){
    vector<vector<int> > matrix;
    vector<int> ans;
    int temp =1 ;
    for (int i = 1; i <4 ; ++i) {
        vector<int> v;
        for (int j = 1; j <5 ; ++j) {
            v.push_back(temp);
            temp++;
        }
        matrix.push_back(v);

    }
    ans = printMatrix(matrix);
    for (int i = 0; i <ans.size() ; ++i){
        cout<< ans[i]<< " ";
    }
    return 0;
}
