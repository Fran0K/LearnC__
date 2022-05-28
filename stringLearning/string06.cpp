//
// Created by Frank Lin on 17/8/21.
//
/*
    string字符存取

    string中单个字符存取方式有两种

    函数原型：
        char& operator[](int n); //通过[]方式取字符
        char& at(int n); //通过at方法获取字符
 */


#include <iostream>
#include <string>
using namespace std;
/*
    string字符存取

    string中单个字符存取方式有两种
        char& operator[](int n); //通过[]方式取字符
        char& at(int n); //通过at方法获取字符
 */
void test01(){
    string s1 = "hello";
    //查找
    for(int i = 0;i<s1.size(); i++){
        cout<< s1.at(i)<<" ";
    }
    cout<<endl;

    //修改
    s1[0] = 'k';
    cout<< s1<<endl;

    s1.at(1) = 'j';
    cout<< s1<<endl;


}
int main(){
    test01();
}