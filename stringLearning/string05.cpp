//
// Created by Frank Lin on 17/8/21.
//
/*
    string字符串比较

    功能描述：
        字符串之间的比较

    比较方式：
        字符串比较是按字符的ASCII码进行对比
            = 返回 0
            > 返回 1
            < 返回 -1

    函数原型：
        int compare(const string &s) const; //与字符串s比较
        int compare(const char *s) const; //与字符串s比较
*/

#include <iostream>
#include <string>
using namespace std;

void test01(){
    string s1 = "xohn";
    string s2 = "john";
    if(s1.compare(s2) == 0){
        cout<< s1<<" is equal to "<<s2;
    } else if (s1.compare(s2) < 0){
        cout<< s1<<" is less than "<<s2;
    } else{
        cout<< s1<<" is larger than "<<s2;
    }

}
int main(){
    test01();
}