//
// Created by Frank Lin on 19/4/2022.
//
#include <vector>
#include <iostream>

using namespace std;

class A{
public:
    A(int x):val(x){
        cout<<"A constructed "<<x<<endl;
    }
    A(){
        cout<<"A default constructed"<<endl;
    }
    ~A(){
        cout<<"A deconstructed,"<<"val is "<<val<<endl;
    }
    int val=0;

};

class B :public A{
public:
    B(int x):val(x){
        cout<<"B constructed "<<x<<endl;

    }
    ~B(){
        cout<<"B deconstructed,"<<"val is "<<val<<endl;
    }
    int val;
};

B c(3);
static A a(2);

int main(){
//    B a = new A;

      A x(5);
      B c(6);
}