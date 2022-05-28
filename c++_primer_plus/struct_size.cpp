//
// Created by Frank Lin on 27/4/2022.
//
#include <iostream>

using namespace std;

struct kk{
    int a;
    char b;
    int z[3] ;
}kk;
struct kk2{

    int z[];

}kk2;

int main(){
    cout<<sizeof (kk)<<endl;
    cout<<sizeof (kk2)<<endl;
}