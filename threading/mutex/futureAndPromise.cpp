//
// Created by Frank Lin on 27/10/21.
//

#include <iostream>
#include <thread>
#include <future>
using namespace std;
using ull = unsigned long long;
void findOddNum(promise<ull>&& oddSumPromise, ull start, ull end){
    ull oddSum=0;
    for(ull i =start; i<end; i++){
        if(i & 1){
            oddSum+=1;
        }
    }
    oddSumPromise.set_value(oddSum);

}

int main(){
    ull start =0, end = 1900000000;
    std::promise<ull> oddSum;
    future<ull> oddFuture = oddSum.get_future();

    cout<< "Thread created"<<endl;
    thread t1(findOddNum, move(oddSum), start, end);

    cout<< "waiting for result "<<endl;

    cout << "result is : " << oddFuture.get()<<endl;

    cout<< "calculation complete "<<endl;
    t1.join();
    return 0;
}