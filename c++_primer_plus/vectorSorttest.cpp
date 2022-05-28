//
// Created by Frank Lin on 16/04/2022.
//

#include <vector>
#include <iostream>
using namespace std;
bool cmp3(vector<int> &a1, vector<int> &a2){
    if(a1[3]==a2[3]){
        return a1[2]>a2[2];
    }
    return a1[3]>a2[3];

}

bool cmp2(vector<int> &a1, vector<int> &a2){
    if(a1[2]==a2[2]){
        return a1[3]>a2[3];
    }
    return a1[2]>a2[2];

}

void printVec(vector<int> &a1){
    for(int i =0;i<a1.size();i++){
        cout<<a1[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<vector<int>> test;
    vector<int> t1={1,2,3,1,5};
    vector<int> t2={2,4,1,2,0};
    vector<int> t3={3,3,4,1,4};
    vector<int> t4={4,2,4,5,6};
    test={t1, t2, t3, t4};
    cout<<"sort 2"<<endl;
    sort(test.begin(), test.end(), cmp2);

    for_each(test.begin(), test.end(), printVec);
    cout<<"sort 2 end"<<endl;
    cout<<endl;
    cout<<"sort 3"<<endl;
    sort(test.begin(), test.end(), cmp3);

    for_each(test.begin(), test.end(), printVec);
    cout<<"sort 3 end"<<endl;
    cout<<endl;


}