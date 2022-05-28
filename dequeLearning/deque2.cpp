//
// Created by Frank Lin on 18/8/21.
//
/*
 * deque大小操作

    功能描述：
        对deque容器的大小进行操作

    函数原型：
        deque.empty(); //判断容器是否为空

        deque.size(); //返回容器中元素的个数

        deque.resize(num); //重新指定容器的长度为num,若容器变长，则以默认值填充新位置。
        ​                    //如果容器变短，则末尾超出容器长度的元素被删除。

        deque.resize(num, elem); //重新指定容器的长度为num,若容器变长，则以elem值填充新位置。
        ​                         //如果容器变短，则末尾超出容器长度的元素被删除。
    PLUS:
        与vector差别在于deque没有capacity()，理论上deque()可以无上限容量操作
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
    if(dq.empty()){
        cout<<"deque is empty"<<endl;
    } else{
        cout<<"deque is not empty"<<endl;
        cout<<"deque size: "<<dq.size()<<endl;
    }
    dq.resize(14,1);
    printDeque(dq);
    cout<<"deque size: "<<dq.size()<<endl;

    dq.resize(5);
    printDeque(dq);
    cout<<"deque size: "<<dq.size()<<endl;

}

int main(){
    test();
}