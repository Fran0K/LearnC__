//
// Created by Frank Lin on 17/8/21.
//


/*
 * vector容量和大小
    功能描述：
        对vector容器的容量和大小操作

    函数原型：

        empty(); //判断容器是否为空

        capacity(); //容器的容量

        size(); //返回容器中元素的个数

        resize(int num); //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
        ​                 //如果容器变短，则末尾超出容器长度的元素被删除。

        resize(int num, elem); //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
                                //如果容器变短，则末尾超出容器长度的元素被删除
 *
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

void test1(){
    vector<int >v1;
    for (int i = 0; i <10 ; ++i) {
        v1.push_back(i);
    }
    printVector(v1);

    //为真，v1为空
    if(v1.empty()){
        cout<<"v1为空"<<endl;
    } else{
        cout<<"v1不为空"<<endl;
        cout<<"v1 capacity: "<<v1.capacity()<<endl;
        cout<<"v1 size: "<<v1.size()<<endl;
    }
    //重新指定size
    v1.resize(15,0);
    printVector(v1);

    //resize短的话，就会删除后面的信息
    v1.resize(8);
    printVector(v1);
}
int main(){
    test1();
    return 0;
}