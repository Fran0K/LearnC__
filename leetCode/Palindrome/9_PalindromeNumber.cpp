//
// Created by Frank Lin on 19/5/2022.
//

//Given an integer x, return true if x is palindrome integer.
//
//An integer is a palindrome when it reads the same backward as forward.
//
//For example, 121 is a palindrome while 123 is not.
#include "vector"

using namespace std;

//class Solution {
//public:
//    bool isPalindrome(int x) {
//        if(x<0){
//            return false;
//        }
//        if(x>=0 && x<=9){
//            return true;
//        }
//        vector<int>a;
//        while(x!=0){
//            a.push_back(x%10);
//            x /=10;
//        }
//        int l=0,r = a.size()-1;
//        while(1){
//            if(a[r]!=a[l]){
//                return false;
//            }
//            r--;
//            l++;
//            if(r<=l){
//                break;
//            }
//
//        }
//        return true;
//    }
//};

//way2
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0||(x!=0 &&x%10==0)){
            return false;
        }
        int sum=0;
        while(x>sum){
            sum = sum*10 + x%10;
            x/=10;
        }
        return (sum==x)|| (x==sum/10);
    }
};

int main(){
    int x = 9;
    Solution().isPalindrome(x);
}