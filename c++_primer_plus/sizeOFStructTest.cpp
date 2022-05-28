//
// Created by Frank Lin on 11/04/2022.
//
#include <iostream>
using namespace std;
struct sdshdr1{
    int len;
    int free;
    char buf[];
};

struct sdshdr2{
    int len;
    int free;
    char buf[0];
};

struct sdshdr3 {
    int len;
    int free;
    char *buf;
};

struct sdshdr4 {
    int len;
    int free;
    char buf[1];
};

int main(){
    cout<< "the size of sdshdr1 are "<<sizeof(sdshdr1)<<endl;
    cout<< "the size of sdshdr2 are "<<sizeof(sdshdr2)<<endl;
    cout<< "the size of sdshdr3 are "<<sizeof(sdshdr3)<<endl;
    cout<< "the size of sdshdr4 are "<<sizeof(sdshdr4)<<endl;
}