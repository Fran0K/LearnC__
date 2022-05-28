//
// Created by Frank Lin on 26/10/21.
//
#include <iostream>
#include <mutex>
#include <thread>


// mutex try lock 如果tryLock是false就会skip循环，知道tryLock为true就会进入循环
//int counter =1;
//std::mutex m;
//void increaseTheCount100000Time(){
//    for(int i =0; i<100000;i++){
//        if(m.try_lock()){
//            ++counter;
//            m.unlock();
//        }
////            m.lock();
////            ++counter;
////            m.unlock();
//        }
//    }
//
//
//int main(){
//
//    std::thread t1(increaseTheCount100000Time);
//    std::thread t2(increaseTheCount100000Time);
//
//    t1.join();
//    t2.join();
//
//    std::cout << "the increment of counter up to "<< counter<< std::endl;
//    return 0;
//}

#include <chrono>
int X =0, Y=0;
std::mutex m1,m2;

void doSomeWorkForSleeping(int seconds){std::this_thread::sleep_for(std::chrono::seconds(seconds));}

void consumeXY(int& XorY, std::mutex &m, const char *desc){
    for (int i = 0; i <5 ; ++i) {
        m.lock();
            ++XorY;
            std::cout<<desc <<XorY << std::endl  ;
        m.unlock();
        doSomeWorkForSleeping(1);

    }

}

//std::try_lock 成功时返回-1，其余返回0
// 用法 int lockResult = std::try_lock(m1, m2);
//        if(lockResult == -1){

void incrementXY(){
    int useCount = 5;
    int XplusY =0;

    while(1){
        int lockResult = std::try_lock(m1, m2);
        if(lockResult == -1){
            if (X!=0 && Y!=0){
                --useCount;
                XplusY +=X+Y;
                X=0;
                Y=0;
                std::cout<< "X PLUS Y : "<<XplusY<<std::endl;
            }
            m1.unlock();
            m2.unlock();
            if(useCount == 0)
                break;

        }
    }


}
int main(){
    std::thread t1(consumeXY, std::ref(X), std::ref(m1), "X: ");
    std::thread t2(consumeXY, std::ref(Y), std::ref(m2), "Y: ");
    std::thread t3(incrementXY);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}