//
// Created by Frank Lin on 14/12/21.
//
#include <iostream>
#include <vector>
using namespace std;
int jump(vector<int>& nums) {
    int n = nums.size(), start = 0 ,end = 0,step=0;

    while(end<n-1){
        step++;
        int maxend = start+1;
        for(int i = start ;i<=end;i++){
            if(i + nums[i] >n-1){
                return step;
            }
            maxend = max(maxend, i + nums[i]);
        }
        start = end+1;
        end = maxend;
    }

    return step;
}

int main(){
    cout<<"helllo";
    vector<int>v1 {2,3,1,1,4};
    jump(v1);
    return 0;

}