//
// Created by Frank Lin on 26/10/21.
//

#include <iostream>
#include <thread>
#include <mutex>
long balance =0;
std::mutex m;

//线程不安全

void addMoney(int money){
    //m.lock();
    balance +=money;
    //m.unlock();

}


int main(){

    std::thread t1(addMoney ,200);
    std::thread t2(addMoney, 100);

    t1.join();
    t2.join();
    std::cout<< "current balance is "<<balance <<std::endl;
    return 0;
}