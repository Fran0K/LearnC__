//
// Created by Frank Lin on 9/5/2022.
//
using namespace std;
class Solution {
public:
    int addDigits(int num) {
        int ans =0;
        while(1){
            while(num>0){
                ans+=(num%10);
                num/=10;
            }
            if(ans>=0 && ans<=9){
                return ans;
            }
            num = ans;
            ans=0;
        }
        return ans;
    }
};

int main(){
    int num = 38;
    Solution().addDigits(num);
}