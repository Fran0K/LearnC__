//
// Created by Frank Lin on 18/8/21.
//

/*
 * deque 插入和删除
    功能描述：
        向deque容器中插入和删除数据

    函数原型：
        两端插入操作：
            push_back(elem); //在容器尾部添加一个数据
            push_front(elem); //在容器头部插入一个数据
            pop_back(); //删除容器最后一个数据
            pop_front(); //删除容器第一个数据

        指定位置操作：
            insert(pos,elem); //在pos位置插入一个elem元素的拷贝，返回新数据的位置。
            insert(pos,n,elem); //在pos位置插入n个elem数据，无返回值。
            insert(pos,beg,end); //在pos位置插入[beg,end)区间的数据，无返回值。
            clear(); //清空容器的所有数据
            erase(beg,end); //删除[beg,end)区间的数据，返回下一个数据的位置。
            erase(pos); //删除pos位置的数据，返回下一个数据的位置。

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
    //尾插
    dq.push_back(10);
    dq.push_back(20);

    //头插
    dq.push_front(30);
    dq.push_front(40);
    printDeque(dq);

    //尾删
    dq.pop_back();
    //头删
    dq.pop_front();

}

void test1(){
    deque<int> dq;
    //尾插
    dq.push_back(10);
    dq.push_back(20);

    //头插
    dq.push_front(30);
    dq.push_front(40);

    //insert
    dq.insert(dq.begin()+3,2,1000);

}
int main(){
    test();
}