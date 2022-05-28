//
// Created by Frank Lin on 8/9/21.
//

//期末预测之安全指数



#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    int count = 0;
    for(int i =0; i<n; i++){
        int w,s;
        cin >> w >> s;
        count += (w*s);
    }

    if (count <= 0){
        cout << 0;
    }else{
        cout << count;
    }
    return 0;
}

