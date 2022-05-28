//
// Created by Frank Lin on 4/5/2022.
//
#include <iostream>

using namespace std;
typedef void(*Fun)();

class Base{
public:
    Base(){};
    virtual void func1(){
        cout<<"Base::fun1()" << endl;
    }
    virtual void func2(){
        cout<<"Base::fun2()" << endl;
    }
    virtual void func3(){
        cout<<"Base::fun3()" << endl;
    }
    ~Base(){};
};

class Derived:public Base{
public:
    Derived(){};
    void fun1()
    {
        cout << "Derived::fun1()" << endl;
    }
    void fun2()
    {
        cout << "DerivedClass::fun2()" << endl;
    }
    ~Derived(){};
};

Fun getAddr(void* obj, uint offset){
    cout<<"======================="<<endl;
    auto v = (unsigned long *)obj;
    auto v1 = *(unsigned long *)obj;
    auto v3 = (void *)(unsigned long *)obj;
    cout<<"v: "<<v<<endl;
    cout<<"v1: "<<v1<<endl;
    cout<<"v3: "<<v3<<endl;
    auto vptr_addr = (void *)*(unsigned long *)obj;
    cout<<"vptr_addr: "<<vptr_addr<<endl;

    void* func_addr = (void *)*((unsigned long *)vptr_addr+offset);
    cout<<"func_addr: "<<func_addr<<endl;
    return (Fun)func_addr;

}

int main(){
    Base ptr;
    Derived d;
    Base *pt = new Derived(); // 基类指针指向派生类实例
    Base &pp = ptr; // 基类引用指向基类实例
    Base &p = d; // 基类引用指向派生类实例
    cout<<"基类对象直接调用"<<endl;
    ptr.func1();
    cout<<"基类对象调用基类实例"<<endl;
    pp.func1();
    cout<<"基类指针指向基类实例并调用虚函数"<<endl;
    pt->func1();
    cout<<"基类引用指向基类实例并调用虚函数"<<endl;
    p.func1();

    // 手动查找vptr 和 vtable
    Fun f1 = getAddr(pt, 0);
    (*f1)();
    Fun f2 = getAddr(pt, 1);
    (*f2)();
    delete pt;
    return 0;

}