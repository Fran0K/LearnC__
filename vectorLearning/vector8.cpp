//
// Created by Frank Lin on 18/8/21.
//

/*
 *
 * vector互换容器
    功能描述：
        实现两个容器内元素进行互换

    函数原型：
        swap(vec); // 将vec与本身的元素互换
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

void test(){

    vector<int> v1;
    for (int i = 0; i <10 ; ++i) {
        v1.push_back(i);
    }
    printVector(v1);
    vector<int> v2;
    for (int i = 10; i >0 ; --i) {
        v2.push_back(i);
    }
    printVector(v2);

    v1.swap(v2);
    printVector(v1);
    printVector(v2);
}

//实际用途
//巧用swap 收缩内存空间
void test1(){
    vector<int> v1;
    for (int i = 0; i <10000 ; ++i) {
        v1.push_back(i);
    }
    cout<<"v1 size: "<<v1.size()<<endl;
    cout<<"v1 capa: "<<v1.capacity()<<endl;

    //resize 后也没有回收空间
    v1.resize(3);
    cout<<"v1 size: "<<v1.size()<<endl;
    cout<<"v1 capa: "<<v1.capacity()<<endl;

    //
    vector<int>(v1).swap(v1);
    //vector<int>(v1) 创建匿名对象
    //swap交换指针
    //且匿名对象在代码结束后回收内存空间

    cout<<"v1 size: "<<v1.size()<<endl;
    cout<<"v1 capa: "<<v1.capacity()<<endl;


}

int main(){
    test1();
    return 0;
}