//
// Created by Frank Lin on 17/8/21.
//

//vector容器嵌套容器

#include <vector>
#include <iostream>
using namespace std;

void test01(){
    //二维数组
    //vector内嵌套数组
    vector<vector<int>>v;

    //创建小容器
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;

    //写入小容器
    //写一维数组
    for (int i = 0; i < 4; ++i) {
        v1.push_back(i+1);
        v2.push_back(i+2);
        v3.push_back(i+3);
        v4.push_back(i+4);
    }

    //小容器写入大容器
    //将所以一维数组放入vector容器，变成二维数组
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    //遍历数组
    for (vector<vector<int >>::iterator it = v.begin(); it != v.end(); it++){
        //(*it)--->vector<int>,还是一个容器
        //for (vector<int>::iterator k = it->begin(); k!=it->end(); k++){
        for (vector<int>::iterator k = (*it).begin(); k!=(*it).end(); k++){
            cout << (*k)<<" ";
        }
        cout<<endl;
    }



}

int main(){
    test01();
}