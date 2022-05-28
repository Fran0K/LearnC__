//
// Created by Frank Lin on 17/8/21.
//
#include <iostream>
using namespace std;

//string 构造函数
/*
 * string();         //创建空字符，eg: string str;
 *
 * sting(const char*s);  //是用字符串s初始化
 *
 * sting(const string& str); //使用一个string对象初始化一个string对象
 *
 * string(int n ,char c)    //使用n个字符c初始化
 *
 * */

void test01(){
    string s1;
    cout<<"s1: "<< s1<<endl;

    const char *str = "hello gg";
    string s2(str);
    cout<<"s2: "<< s2<<endl;

    string s3(s2);
    cout<<"s3: "<<s3<<endl;

    string s4(10,'a');
    cout<<"s4: "<< s4<<endl;
}

int main(){
    test01();
    return 0;
}