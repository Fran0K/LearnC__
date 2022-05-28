//
// Created by Frank Lin on 18/8/21.
//

/*
 *deque 排序
    功能描述：
        利用算法实现对deque容器进行排序

    算法：
        sort(iterator beg, iterator end) //对beg和end区间内元素进行排序
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
    deque<int> d;
    d.push_back(10);
    d.push_back(23);
    d.push_back(200);
    d.push_front(300);

    printDeque(d);
    //排序， 从小到大
    //支持随机访问的迭代器的容器，可以利用sort函数进行排序
    sort(d.begin(), d.end());

    printDeque(d);
}

int main(){
    test();
}
