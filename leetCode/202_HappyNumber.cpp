//
// Created by Frank Lin on 20/5/2022.
//
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        if(n>1&&n<10){
            return false;
        }

        while(1){
            int sum =0;
            while(n>0){
                int k = n%10;
                sum+=(k*k);
                n/=10;
            }
            if(sum==1){
                break;
            }
            else if(sum<=9){
                return false;
            }
            n=sum;
        }
        return true;
    }
};

int main(){
    int n = 19;
    Solution().isHappy(n);
}