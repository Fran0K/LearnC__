//
// Created by Frank Lin on 27/4/2022.
//
#include <iostream>

using namespace std;

int main(){
    int a[5] = {1,2,3,4,5};
    cout<<&a<<endl;
    cout<<&a+1<<endl;
    //int *k= (&a+1);
    int *ptr = (int *)(&a + 1);
    cout<<*ptr<<endl;
    printf("%d, %d", *(a + 1), *(ptr - 1));
}