//
// Created by Frank Lin on 19/4/2022.
//
#include <string>
#include <iostream>
using namespace std;
int main(){
//    std::string s1= "abc";
//    string s2 = "abc";
//    bool k = s1==s2;
//    cout<<k<<endl;
//    cout<<s1.compare(s2)<<endl;
    int a =0;
    char b = '0';
    string c="0";
    float  d= 0.0;
    cout<<"a:"<<sizeof(a)
        <<" b:"<<sizeof(b)
        <<" c:"<<sizeof(c)
        <<" d:"<<sizeof(d)<<endl;

    int k= 4;
    k+=k*k;
    cout<< k;

}