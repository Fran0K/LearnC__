//
// Created by Frank Lin on 26/10/21.
//


//1.如果互斥锁当前未被任何线程锁定，则调用线程将其锁定（从此点开始，直到调用其成员解锁，该线程拥有互斥锁）。
//2.如果互斥锁当前被另一个线程锁定，则该函数将失败并返回false，而不会阻塞（调用线程继续执行）。
//3.如果互斥锁当前被调用此函数的同一线程锁定，则会产生死锁（具有未定义的行为）。
// 请参阅recursive_mutex以获取允许来自同一线程的多个锁的互斥锁类型。

#include <iostream>
#include <thread>
#include <mutex>
int myAccount = 0;

std::mutex m;

void addMoney(){
    m.lock();
    ++myAccount;
    m.unlock();
}

int main(){
    std::thread t1(addMoney);
    std::thread t2(addMoney);

    t1.join();
    t2.join();

    std::cout<<myAccount<<std::endl;
    return 0;
}