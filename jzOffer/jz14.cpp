//
// Created by Frank Lin on 30/10/21.
//

#include <iostream>
#include <vector>
using namespace std;


int cutRope(int number) {
    vector<int> dp(number,0);
    if(number == 2){
        return 1;
    }else if(number == 3){
        return 2;
    }
    dp[2] = 1;
    dp[3] = 2;
    for(int i =4; i<number;i++){
        for(int j = 1; j<i;j++){
            int temp = dp[i-j];
            dp[i] = max(dp[i],max(j*(i-j),j*dp[i-j]));
        }

    }
    return dp[number];
}


int main(){
    int kk = cutRope(8);
    cout<<kk;
    return 0;
}