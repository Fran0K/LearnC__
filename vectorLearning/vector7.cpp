//
// Created by Frank Lin on 18/8/21.
//

/*
 *
 * vector数据存取
    功能描述：
        对vector中的数据的存取操作

    函数原型：
        at(int idx); //返回索引idx所指的数据
        operator[]; //返回索引idx所指的数据
        front(); //返回容器中第一个数据元素
        back(); //返回容器中最后一个数据元素

 * */
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int>& v) {

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void test(){
    vector<int> v1;
    for (int i = 0; i <10 ; ++i) {
        v1.push_back(i);
    }

    //利用[]访问
    for (int j = 0; j <v1.size() ; ++j) {
        cout<<v1[i]<<" ";
    }
    cout<<endl;

    //利用at方式访问元素
    for (int j = 0; j <v1.size() ; ++j) {
        cout<<v1.at(i)<<" ";
    }
    cout<<endl;

    //访问第一个元素
    cout << "the first ele: "<<v1.front() << endl;

    //访问最后一个元素；
    cout << "the last ele: "<<v v1.back() << endl;

}

int main(){
    test();
    return 0;
}