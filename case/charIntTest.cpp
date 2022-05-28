//
// Created by Frank Lin on 09/03/2022.
//
#include <iostream>
int main(){
    char s ='s';
    int i =1;
    if(typeid(s+i)== typeid(int)){
        std::cout<<"int";

    }
    if(typeid(s+i)== typeid(char)){
        std::cout<<"char";

    }
    int k=0;
}