//
// Created by Frank Lin on 17/8/21.
//
#include <iostream>
#include <string>
using namespace std;
/*
    string字符串拼接

    功能描述：
        实现在字符串末尾拼接字符串

    函数原型：
        string& operator+=(const char* str); //重载+=操作符
        string& operator+=(const char c); //重载+=操作符
        string& operator+=(const string& str); //重载+=操作符
        string& append(const char *s); //把字符串s连接到当前字符串结尾
        string& append(const char *s, int n); //把字符串s的前n个字符连接到当前字符串结尾
        string& append(const string &s); //同operator+=(const string& str)
        string& append(const string &s, int pos, int n);//字符串s中从pos开始的n个字符连接到字符串结尾
*/
void test01(){
    string s1 ="what ";
    s1+= "the fuck";
    cout<<s1<<endl;
    s1.append(" u r doing");
    cout<<s1<<endl;
}

int main(){
    test01();
}