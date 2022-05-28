//
// Created by Frank Lin on 26/10/21.
//
#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

//int account=0;
//std::timed_mutex m;
//void increment(int i){
//    if(m.try_lock_for(std::chrono::seconds(1))){
//        ++account;
//        std::this_thread::sleep_for(std::chrono::seconds(2));
//        std::cout<< "thread "<<i << " entered"<< std::endl;
//        m.unlock();
//    }else{
//        std::cout<< "thread "<<i << " couldn't enter"<< std::endl;
//    }
//}
//
//
//int main(){
//
//    std::thread t1(increment, 1);
//    std::thread t2(increment, 2);
//
//    t1.join();
//    t2.join();
//
//    std::cout<< account<< std::endl;
//    return 0;
//}



int account=0;
std::timed_mutex m;
void increment(int i){
    auto now = std::chrono::steady_clock::now();
    if(m.try_lock_until(now+std::chrono::seconds(1))){
        ++account;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout<< "thread "<<i << " entered"<< std::endl;
        m.unlock();
    }else{
        std::cout<< "thread "<<i << " couldn't enter"<< std::endl;
    }
}


int main(){

    std::thread t1(increment, 1);
    std::thread t2(increment, 2);

    t1.join();
    t2.join();

    std::cout<< account<< std::endl;
    return 0;
}