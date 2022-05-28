//
// Created by Frank Lin on 25/10/21.
//

#include <iostream>
#include <thread>
using namespace std;
//方式1 函数
//void  func(int x){
//    while (x-->0){
//        cout<<x<<endl;
//    }
//}
//
//int main(){
//    thread t1(func, 10);
//    t1.join();
//
//    return 0 ;
//}

//方式2 lambda 函数

//1.
//int main(){
//    auto func = [](int x){
//        while(x-- >0){
//            cout<<x<<endl;
//        }
//    };
//
//    thread t1(func, 10);
//    t1.join();
//
//    return 0 ;
//}

//2.
//int main(){
//
//    thread t1([](int x){
//        while(x-- >0){
//            cout<<x<<endl;
//        }
//    }, 10);
//    t1.join();
//
//    return 0 ;
//}



//方式3 Function(Function 对象）
//class Base{
//    public:
//    void operator() (int x){
//        while (x-->0){
//            cout<<x<<endl;
//        }
//    }
//};
//
//int main(){
//    thread t1(Base(), 10);
//    t1.join();
//
//    return 0 ;
//}


//4. Non-static member function
// 非静态成员函数
//class Base{
//    public:
//    void run (int x){
//        while (x-->0){
//            cout<<x<<endl;
//        }
//    }
//};
//
//int main(){
//    Base b;
//    //类的那个函数， 对应类的object， 传值
//    thread t1(&Base::run, &b, 10);
//    t1.join();
//
//    return 0 ;
//}

//5.static member function
// 静态成员函数
class Base{
    public:
    static void run (int x){
        while (x-->0){
            cout<<x<<endl;
        }
    }
};

int main(){
    //类的那个函数， 对应类的object， 传值
    thread t1(&Base::run, 10);
    t1.join();

    return 0 ;
}