//
// Created by Frank Lin on 14/04/2022.
//
#include <iostream>
using namespace std;

int main(){
    int k = 5;

    int *p =&k;
    cout<<"*p is "<< *p<<endl;
    cout <<"p is "<<p<<endl;

    int a1[2]={100,200};
    int a[2]={10,20};

    const int *b = &a[0];
    int * const p2 = &a[0];
    cout<< *(b+1)<<endl;
    cout<< *(p2)+3;

}