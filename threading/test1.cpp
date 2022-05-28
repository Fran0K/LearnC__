//
// Created by Frank Lin on 12/1/22.
//
#include <iostream>
#include <thread>
using namespace std;
int n =0;
void increase(){
    for(int i=0; i<1000;i++){
        n++;
    }
}

int main(){
    for(int i=0; i<10;i++){
        std::thread(increase);
    }
    cout<<n<<endl;
    return 0;
}