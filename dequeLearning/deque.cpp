//
// Created by Frank Lin on 18/8/21.
//

/*
 * deque构造函数
    功能描述：
        deque容器构造

    函数原型：
        deque<T> deqT; //默认构造形式
        deque(beg, end); //构造函数将[beg, end)区间中的元素拷贝给本身。
        deque(n, elem); //构造函数将n个elem拷贝给本身。
        deque(const deque &deq); //拷贝构造函数
 * */

#include <deque>
#include <iostream>
#include <algorithm>
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

void test(){
    deque<int> dq;
    for (int i = 0; i <10 ; ++i) {
        dq.push_back(i);
    }
    printDeque(dq);

    deque<int> d2(dq.begin(), dq.end());
    printDeque(d2);

    deque<int> d3(10,100);
    printDeque(d3);

    deque<int> d4(d3);
    printDeque(d4);
}
int main(){
    test();
}