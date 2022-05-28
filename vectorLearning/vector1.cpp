//
// Created by Frank Lin on 16/8/21.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printFunc(int x){
    cout << x << endl;
}

void test1(){
    //创建vector 容器 数组，类型为int
    vector<int> v;

    //push_back 往vector内塞数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    //是用迭代器遍历数据
    for_each(v.begin(), v.end(), printFunc);
}

int main(){
   test1();
}