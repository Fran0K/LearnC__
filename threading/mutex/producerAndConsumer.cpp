//
// Created by Frank Lin on 27/10/21.
//
//
//Producer Consumer OR Bounded Buffer Problem
//THE PROBLEM STATEMENT
//1. Producer will produce and consumer will consume with synchronization of a common buffer.
//2. Until producer thread produces any data consumer thread can't consume
//3. Threads will use condition variable to notify each other
//4. We need mutex if we use condition variable because CV waits on mutex
//5. This is one of the example of producer consumer there are many
//PRODUCER thread steps
//1. lock mutex, if success then go ahead otherwise wait for mutex to get free
//2. check if buffer is full and if it is full then unlock mutex and sleep, if not then go ahead and produce
//3. insert item in buffer
//4. unlock mutex
//5. notify consumer.
//CONSUMER thread steps
//1. lock mutex, if success then go ahead otherwise wait for mutex to get free
//2. check if buffer is empty and if it is, then unlock the mutex and sleep, if not thean go ahead and consume.
//3. consume item from buffer
//4. unlock mutex
//5. notify producer.
//Producer and Consumer have to notify each other upon comletion of their job



#include <iostream>
#include <thread>
#include <condition_variable>
#include <deque>

const unsigned int maxBufferSize = 2;
std::condition_variable cond;
std::deque<int> dq;
std::mutex m;

void producer(int val){
    while(val >0){
        std::unique_lock<std::mutex> locker(m);
        cond.wait(locker, [] {return dq.size()<maxBufferSize;} );
        std::cout<<"Produced : "<< val<<std::endl;
        dq.push_back(val);
        val--;
        locker.unlock();
        cond.notify_one();
    }
}

void consumer(){
    while(true){
        std::unique_lock<std::mutex> locker(m);
        cond.wait(locker, []{return dq.size()>0;});
        int val = dq.back();
        std::cout<<"Consumed : "<< val<<std::endl;
        dq.pop_back();
        locker.unlock();
        cond.notify_one();
    }
}

int main(){
    std::thread t1(producer, 100);
    std::thread t2(consumer);

    t1.join();
    t2.join();

    return 0;

}