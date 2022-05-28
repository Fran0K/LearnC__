//
// Created by Frank Lin on 16/04/2022.
//
#include <iostream>
using namespace std;
class A{
    int val;
public:
    A(int n ){
        val = n;
    }
    A(A other){
        val = other.val;
    }
    void print(){
        cout<< "val: "<<val<<endl;
    }
};

int main(){
    A a = 3;
    A b = a;
    a.print();
    b.print();
}
