//
// Created by Frank Lin on 25/4/2022.
//
#include <iostream>

using namespace std;

class Singleton{
public:
    static Singleton* GetInstance(){
        return singleton_;
    }

    static void DestroyInstance(){
        if(singleton_ != NULL){
            delete singleton_;
        }
    }

private:
    Singleton()=default;
    Singleton& operator=(const Singleton&)=delete;
    Singleton (const Singleton& singleton2)=delete;

private:
    static Singleton* singleton_;
};

Singleton* Singleton::singleton_ = new Singleton;

int main() {
    Singleton* s1 = Singleton::GetInstance();
    std::cout << s1 << std::endl;
}