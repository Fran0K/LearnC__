//
// Created by Frank Lin on 26/10/21.
//
//IMPORTANT POINT: CV are used for two purpose
//A. Notify other threads
//B. Waiting for some conditions

//1.Condition Variable allows running threads to wait on some conditions and
//  once those conditions are met the waiting thread is notified using
//   a. notify one()
//   b. notify all
//2.You need mutex to use condition variable
//3. If some thread want to wait on some condition then it has to do these things
//  a, Acquire the mutex Lock using std: unique Lock<std: mutex> Lock(m)
//  b. Execute wait, wait for, or wait until. The wait operations atomically release the mutex and
//     suspend the execution of the thread
//  c. When the condition variable is notified, the thread is awakened, and the mutex is atomically reacquired
//     The thread should then check the condition and resume waiting if the wake up was spurious
//
// NOTE
//   1. Condition variables are used to synchronize two or more threads
//   2. Best use case of condition variable is Producer/Consumer problem


#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
long balance =0;
std::condition_variable cv;
std::mutex m;

void addMoney(int money){
    std::lock_guard<std::mutex> lg(m);
    balance +=money;
    std::cout<< "add Money: "<<money<<std::endl;
    cv.notify_one();
}

void withDrawMoney(int money){
    std::unique_lock<std::mutex> ul(m);
    //等待blance值是否为0
    cv.wait(ul, []{ return (balance != 0)? true: false;});
    if(balance> money){
        balance-=money;
        std::cout<< "amount deducted: "<<balance<<std::endl;
    } else{
        std::cout<< "amount deducted failed, current balance is less than: "<<money<<std::endl;
    }
    std::cout<< "amount current balance is: "<<balance<<std::endl;

}

int main(){
    std::thread t1(addMoney ,500);
    std::thread t2(withDrawMoney, 600);

    t1.join();
    t2.join();

    return 0;
}
