//
// Created by Frank Lin on 20/5/2022.
//
#include <iostream>
using namespace std;

class Base {
public:
    virtual void a() { cout << "Base a()" << endl; }
    virtual void b() { cout << "Base b()" << endl; }
};

class Derive : public Base {
public:
    virtual void a() { cout << "Derive a()" << endl; } // 覆盖Base::a()
    virtual void c() { cout << "Derive a()" << endl; } // 覆盖Base::a()
};

//int main(){
//    cout << "-----------打印 class Base------------" << endl;
//    Base base;
//    printf("&base = %p\n", &base);
//    printf("&Base::a = %p\n", &Base::a);
//    printf("&Base::b = %p\n", &Base::b);
//
//    cout << "-----------打印 class Derive------------" << endl;
//    Derive derive;
//    printf("&derive = %p\n", &derive);
//    printf("&Derive::a = %p\n", &Derive::a);
//    printf("&Derive::b = %p\n", &Derive::b);
//    printf("&Derive::c = %p\n", &Derive::c);
//    return 0;
//}

//int main(){
//    //创建一个函数指针
//    //指针名为Fun，参数void，返回类型void
//
//    //typedef 返回类型(*新类型)(参数表)
//    //创建新类型 Fun
//    typedef void(*Fun)(void);
//
//    Derive d1;
//    //&d1 取d1对象地址，(Fun**)&d1对d1地址转换为(Fun**)类型
//
//    Fun **vt_ptr = (Fun**)&d1;
//
//
//
//    cout << "-----------第一次打印虚函数地址------------" << endl;
//    printf("&d1 : %p\n", &d1);
//    for(int i =0;i<3;i++){
//        printf("[d1] vptr[%d] : %p\n", i, *(*vt_ptr+i));
//    }
//    Derive d2;
//    vt_ptr = (Fun**)&d2;
//    cout << "-----------第二次打印虚函数地址------------" << endl;
//    printf("&d2 : %p\n", &d2);
//    for (int i = 0; i < 3; i++) {
//        printf("[d2] vptr[%d] : %p\n", i, *(*vt_ptr + i));
//    }
//
//}

int main(){
    typedef void(*func)(void*);
    Derive *p = new Derive;
    //虚函数表指针
    long *temp = (long *)p;
    // 获取虚函数的内容
    // 首先解引用，获取内容-》虚函数函数
    // 然后再转换为地址
    long *vptr =  (long *)(*temp);
    for(int i =0;i<2;i++){
        printf("Derive vptr[%d] : %p\n", i, vptr[i]);
    }
    Base *t = new Base;
    long *ptr1 = (long*)t;
    long *ptv1 = (long*)(*ptr1);
    for(int i =0;i<2;i++){
        printf("base vptr[%d] : %p\n", i, vptr[i]);
    }

    auto f1 = (func*)(vptr[0]);


}
