//
// Created by Frank Lin on 17/8/21.
//
/*
 * string子串
    功能描述：
        从字符串中获取想要的子串

    函数原型：
        string substr(int pos = 0, int n = npos) const; //返回由pos开始的n个字符组成的字符串
*/
#include <iostream>
#include <string>
using namespace std;

void test01(){
    string s1 = "john";
    string sub = s1.substr(1,3);

    cout<<sub<<endl;

}

void test2(){
    //提取email的用户名
    string email = "johnwick@gmail.com";

    int pos = email.find('@');

    string name = email.substr(0, pos);

    cout<<name<<endl;
}

int main() {
    test2();
}