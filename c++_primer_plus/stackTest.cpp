//
// Created by Frank Lin on 12/04/2022.
//

#include <iostream>
void fun(int a)
{
    a += 1;
    std::cout<<"Hello World!";
}

int main(){
    int val =1;
    fun(val);
    return 0;
}