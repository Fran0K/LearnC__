//
// Created by Frank Lin on 12/04/2022.
//
#include <iostream>
using namespace std;

class A{
public:
    virtual void f(){
        cout<<"A f() is executing"<<endl;
    }
     void f2(){
        cout<<"A f2() is executing"<<endl;
    }
};

class B:public A{
public:
    void f(){
        cout<<"B f() is executing"<<endl;
    }
};

int main(){
    B *b= new B();
    b->f();
    b->f2();

}


