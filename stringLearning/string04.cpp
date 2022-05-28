//
// Created by Frank Lin on 17/8/21.
//
#include <iostream>
#include <string>
using namespace std;
/*
 *  string查找和替换
 *
    功能描述：
        查找：查找指定字符串是否存在
        替换：在指定的位置替换字符串

    函数原型：
        int find(const string& str, int pos = 0) const; //查找str第一次出现位置,从pos开始查找
        int find(const char* s, int pos = 0) const; //查找s第一次出现位置,从pos开始查找
        int find(const char* s, int pos, int n) const; //从pos位置查找s的前n个字符第一次位置
        int find(const char c, int pos = 0) const; //查找字符c第一次出现位置
        int rfind(const string& str, int pos = npos) const; //查找str最后一次位置,从pos开始查找
        int rfind(const char* s, int pos = npos) const; //查找s最后一次出现位置,从pos开始查找
        int rfind(const char* s, int pos, int n) const; //从pos查找s的前n个字符最后一次位置
        int rfind(const char c, int pos = 0) const; //查找字符c最后一次出现位置

        string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
        string& replace(int pos, int n,const char* s); //替换从pos开始的n个字符为字符串s

 * */

void test01(){
    string s1 = "jowickisgunshwooter";
    int pos = s1.find("w");
    if (pos ==-1){
        cout<< "no pos"<<endl;
    }else{
        cout<< pos<<endl;
    }

    //rfind与find的区别
    // rfind从右往左查
    // find从左到右查
    int kk = s1.rfind("w");
    cout<<"kk:"<<kk<<endl;

}

//替换
void test02(){
    string s1 = "john wick ex";
    //从1号位置起 ，将2个字符，替换为kksda
    s1.replace(1, 2, "kksda");
    cout<<"s1:"<<s1<<endl;
}


int main(){
    test02();
    return 0;
}