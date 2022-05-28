//
// Created by Frank Lin on 26/10/21.
//


#include <iostream>
#include <mutex>
#include <thread>

//std::mutex m1;
////std::mutex m1;
//
//int buffer =0;
//void recursion(const char* c,int loop ){
//    std::unique_lock<std::mutex> lock(m1);
//    for(int i = 0; i<loop; i++){
//        std::cout <<c<<" "<<buffer++ << std::endl;
//
//    }
//}
//
//int main(){
//
//    std::thread t1(recursion, "T0", 10);
//    std::thread t2(recursion, "T1", 10);
//
//    t1.join();
//    t2.join();
//
//    return 0;
//}


std::mutex m1;
//std::mutex m1;

int buffer =0;
void recursion(const char* c,int loop ){
    std::unique_lock<std::mutex> lock(m1, std::defer_lock); //defer_lock就不需要指明mutex m1
    //lock.lock(); // 要指明是在哪里lock
    for(int i = 0; i<loop; i++){
        std::cout <<c<<" "<<buffer++ << std::endl;

    }
}

int main(){

    std::thread t1(recursion, "T0", 10);
    std::thread t2(recursion, "T1", 10);

    t1.join();
    t2.join();

    return 0;
}