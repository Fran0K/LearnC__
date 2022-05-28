//
// Created by Frank Lin on 18/8/21.
//

/*
 * deque 数据存取
    功能描述：
        对deque 中的数据的存取操作

    函数原型：
        at(int idx); //返回索引idx所指的数据
        operator[]; //返回索引idx所指的数据
        front(); //返回容器中第一个数据元素
        back(); //返回容器中最后一个数据元素
 *
 * */

#include <deque>
#include <iostream>
using namespace std;


void test(){
    deque<int> d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_back(30);
    d1.push_back(40);


    for (int i = 0; i <d1.size() ; ++i) {
        cout << d1[i]<<" ";
    }
    cout<<endl;

    //at访问
    for (int i = 0; i <d1.size() ; ++i) {
        cout << d1.at(i)<<" ";
    }
    cout<<endl;

    //第一个元素
    cout << d1.front()<<" ";
    cout<<endl;

    //最后一个元素
    cout<< d1.back() <<" ";
    cout<<endl;
}

