//
// Created by Frank Lin on 27/10/21.
//

#include <iostream>
#include <thread>
#include <future>
using namespace std;
using ull = unsigned long long;
ull findOddNum(ull start, ull end){
    cout << "findOddNum thread id : " << std::this_thread::get_id()<<endl;
    ull oddSum=0;
    for(ull i =start; i<end; i++){
        if(i & 1){
            oddSum+=1;
        }
    }
    return oddSum;

}

int main(){
    ull start =0, end = 1900000000;
    cout << "thread id : " << std::this_thread::get_id()<<endl;
    future<ull> oddFuture = std::async(std::launch::async, findOddNum, start, end);

    cout<< "Thread created"<<endl;

    cout<< "waiting for result "<<endl;

    cout << "result is : " << oddFuture.get()<<endl;

    cout<< "calculation complete "<<endl;

    return 0;
}