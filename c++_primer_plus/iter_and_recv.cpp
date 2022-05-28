//
// Created by Frank Lin on 3/11/21.
//

//
// Created by Frank Lin on 3/11/21.
//
#include <iostream>
#include <cmath>
using namespace std;

void recu(int n){
    cout << "recu for "<<n<<endl;
    if (n>0){
        recu(n-1);
    }
    cout << "recu for "<<n<< " recu address: "<<&n<<endl;

}

void iter(int n){
    cout<<endl;
    cout<< "start iteration "<<endl;
    for(int i = 0;i<n;i++){
        cout << "iter for "<<i<<endl;
        cout << "iter for "<<i<< "its address: "<< &i<<endl;

    }
    cout<< "end iteration "<<endl;


}
int main(){
    recu(4);
    iter(4);
    return 0;
}