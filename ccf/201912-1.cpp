//
// Created by Frank Lin on 14/9/21.
//
#include <iostream>
using namespace std;

bool numberWithSeven(int num){
    while(num >0){
        int last = num%10;
        if(last == 7 || num == 7){
            return true;
        }
        num = num/10;
    }
    return false;
}


int main(){
    int num[5]= {0};
    int n;
    cin >> n;
    int count = 1;
    int i = 1 ;
    int pos =1;
    while(count <= n){
        if(i%7 == 0 || numberWithSeven(i)){
            num[pos]++;
            count--;
        }
        count++;
        i++;
        pos++;
        if(pos == 5)pos =1;
    }

//
    for (int i = 1; i <5 ; ++i){
        cout<< num[i]<<endl;
    }
    return 0;
}
