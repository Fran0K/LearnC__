//
// Created by Frank Lin on 26/10/21.
//
// NOTES:
// 0. It is same as mutex but, Same thread can Lock one mutex multiple times using recursive mutex
// 1. If thread T1 first call Lock/try Lock on recursive mutex ml, then ml 1s Locked by T1, now
//     as T1 is running in recursion T1 can call Lock/try Lock any number of times there is no issue
// 2. But if Tl have aquired 10 times Lock/try Lock on mutex ml then thread T1 will have to unlock
//    it 10 times otherwise no other thread will be able to Lock mutex ml
//    It means recursive mutex keeps count how many times it was Locked so that many times it should be un Locked //3. How many time we can Lock recursive mutex is not defined but when that number reaches and if we were calling
//    Lock() it will return std: system error OR if we were calling try Lock()then it will return false
//BOTTOM LINE:
// 1. If we can avoid recursive mutex then we should becuase it brings overhead to the syste Same thread //0. It is similar to mutex but have extra facitility that it can be Locked multiple time by
// 2. It can be used in Loops also.


#include <iostream>
#include <mutex>
#include <thread>

std::recursive_mutex m1;
//std::mutex m1;

int buffer =0;
void recursion(char c,int loopFor ){
    if(loopFor < 0){
        return;
    }
    m1.lock();
    std::cout <<c<<" "<<buffer++ << std::endl;
    recursion(c , --loopFor);
    m1.unlock();

}

int main(){

    std::thread t1(recursion, '0', 10);
    std::thread t2(recursion, '1', 10);

    t1.join();
    t2.join();

    return 0;
}