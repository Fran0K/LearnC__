//
// Created by Frank Lin on 17/8/21.
//

/*
 *  string插入和删除

    功能描述：
        对string字符串进行插入和删除字符操作

    函数原型：
        string& insert(int pos, const char* s); //插入字符串
        string& insert(int pos, const string& str); //插入字符串
        string& insert(int pos, int n, char c); //在指定位置插入n个字符c
        string& erase(int pos, int n = npos); //删除从Pos开始的n个字符
*/

#include <iostream>
#include <string>
using namespace std;

void test01(){
    string s1 = "john";
    string s2 = "john";

    //插入
    s1.insert(2,"hjshdk");
    cout<<s1<<endl;

    //删除
    s1.erase(2,5);
    cout<<s1<<endl;
}
int main() {
    test01();
}