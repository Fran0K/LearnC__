//
// Created by Frank Lin on 20/2/22.
//

#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Solution {
public:
//    int LastRemaining_Solution(int n, int m) {
//        vector<int> ans(n,0);
//        int pt =0;
//        int count = 0;
//        int s =n;
//        while(1){
//            pt = (pt<n)?pt: pt%n;
//            if(count == m-1){
//                //first
//                if(ans[pt] == 0 ){
//                    ans[pt]++;
//                    count =0;
//                    s--;
//                    pt++;
//                }else{
//                    while(ans[pt] != 0){
//                        pt++;
//                        if(pt==n){
//                            pt =0;
//                        }
//                    }
//                    ans[pt]++;
//                    count =0;
//                    s--;
//                    pt++;
//                }
//            }else{
//                count++;
//                pt++;
//            }
//
//            if(s ==1){
//                break;
//            }
//
//
//        }
//
//        for(int i =0 ;i<n ;i++){
//            if(ans[i]==0){
//                return i;
//            }
//        }
//
//    }
    int LastRemaining_Solution(int n, int m){
        if(n<0){
            return -1;
        }
        list<int> l;
        for(int i =0 ;i<n;i++){
            l.push_back(i);
        }
        int index =0;
        while(n>1){
            index = (index + m-1)%n;
            auto iter =l.begin();
            int k = index;
            while(k--){
                iter++;
            }
            l.erase(iter);
            n--;
        }
        return l.back();
    }
};

int main(){
    Solution().LastRemaining_Solution(5,3);

}