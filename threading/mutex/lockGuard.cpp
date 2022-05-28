//
// Created by Frank Lin on 26/10/21.
//


#include <iostream>
#include <mutex>
#include <thread>

std::mutex m1;
//std::mutex m1;

int buffer =0;
void recursion(char c,int loop ){
    std::lock_guard<std::mutex> lock(m1);
    for(int i = 0; i<loop; i++){
        std::cout <<c<<" "<<buffer++ << std::endl;

    }
}

int main(){

    std::thread t1(recursion, '0', 10);
    std::thread t2(recursion, '1', 10);

    t1.join();
    t2.join();

    return 0;
}