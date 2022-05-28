//
// Created by Frank Lin on 23/5/2022.
//
#include "string"
#include "iostream"
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==1){
            return n;
        }
        int ans =1;
        int c =1;
        int n2=2,n3=3,n5=5;
        int p2=1,p3=1,p5=1;
        while(c!=n){
            n2 = p2*2;
            n3 = p3*3;
            n5 = p5*5;
            int mi = min(n2,min(n3,n5));
            ans = mi;
            c++;
            if(mi == n2){
                p2++;
            }
            if(mi == n3){
                p3++;
            }
            if(mi == n5){
                p5++;
            }
        }
        return ans;
    }
};

int main(){
    int n = 11;
    int a = Solution().nthUglyNumber(n);
    std::cout<< a;
}