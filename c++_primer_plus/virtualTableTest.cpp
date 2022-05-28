//#include "iostream"
//
//using namespace std;
//
//class Base{
//public:
//    virtual void a(){
//        cout<<"Base::a() executed"<<endl;
//    }
//    virtual void b(){
//        cout<<"Base::b() executed"<<endl;
//    }
//    virtual void c() {
//        cout << "Base::c() executed" << endl;
//    }
//};
//
//class Derived:public Base{
//    virtual void b() { cout << "Derive b()" << endl; }
//};
//
//int main(){
//    typedef void(*Func)(void);
//    //指针p指向derived；
//    cout<<"------Derived-----"<<endl;
//    Derived *p = new Derived;
//    cout<<p<<endl;
//    long* ptr = (long*)p;
//    long* vtb = (long*)(*ptr);
//    for(int i =0;i<3;i++){
//        cout<<i<<" "<< &vtb[i]<<endl;
//        Func a = (Func)(vtb[i]);
//        a();
//    }
//
//    cout<<"------Base-----"<<endl;
//    Base *b = new Base;
//    long* ptr_b = (long*)b;
//    long* vtb_b = (long*)(*ptr_b);
//    cout<< vtb_b<<endl;
//    for(int i =0;i<3;i++){
//        cout<<i<<" "<< &vtb_b[i]<<endl;
//        Func a = (Func)(vtb_b[i]);
//        a();
//    }
//
//}

#include <iostream>
#include <stdio.h>
using namespace std;

class Base {
public:
    virtual void a() { cout << "Base a()" << endl; }
    virtual void b() { cout << "Base b()" << endl; }
    virtual void c() { cout << "Base c()" << endl; }
};

class Derive : public Base {
public:
    virtual void b() { cout << "Derive b()" << endl; }
};

int main()
{
    typedef void (*Func)();
    cout << "-----------Base------------" << endl;
    Base* q = new Base;
    Base b;
//    cout<<"Base::a"<<&Base::a()<<endl;
    long* tmp1 = (long*)q;
    cout<<"temp1:"<<tmp1<<" *temp1:"<<*tmp1<<endl;
    long* vptr1 = (long*)(*tmp1);
    for (int i = 0; i < 3; i++) {
        printf("vptr[%d] : %p\n", i, vptr1[i]);
    }
    Func a = (Func)vptr1[0];
    Func b = (Func)vptr1[1];
    Func c = (Func)vptr1[2];
    a();
    b();
    c();

    Derive* p = new Derive;
    long* tmp = (long*)p;
    long* vptr = (long*)(*tmp);
    cout << "---------Derive------------" << endl;
//    for (int i = 0; i < 3; i++) {
//        printf("vptr[%d] : %p\n", i, vptr[i]);
//    }
    Func d = (Func)vptr[0];
    Func e = (Func)vptr[1];
    Func f = (Func)vptr[2];
    d();
    e();
    f();


    return 0;
}