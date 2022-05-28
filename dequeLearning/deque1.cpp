//
// Created by Frank Lin on 18/8/21.
//
/*
 * deque赋值操作

    功能描述：
        给deque容器进行赋值

    函数原型：
        deque& operator=(const deque &deq); //重载等号操作符

        assign(beg, end); //将[beg, end)区间中的数据拷贝赋值给本身。

        assign(n, elem); //将n个elem拷贝赋值给本身。
 * */

#include <deque>
#include <iostream>

using namespace std;

//聊聊const
//print函数的功能我们希望不改变任何数据
//所以在参数里面加个const
//const的话iterator也要有const
void printDeque(const deque<int>&q){
    for(deque<int>::const_iterator it = q.begin(); it!= q.end(); it++){
        cout<< *it <<" ";
    }
    cout<<endl;
}

void test() {
    deque<int> dq;
    for (int i = 0; i < 10; ++i) {
        dq.push_back(i);
    }
    printDeque(dq);

    //赋值
    deque<int> d2;
    d2 = dq;
    printDeque(d2);

    deque<int> d3;
    d3.assign(dq.begin(), dq.end());
    printDeque(d3);

    deque<int> d4;
    d4.assign(10, 100);
    printDeque(d4);
}

int main(){
    test();
    return 0;
}