//
// Created by Frank Lin on 04/03/2022.
//
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n= nums.size()-1;
        quickS(nums,0,n);
    }
    void quickS(vector<int>& nums, int start, int end){


        if(end>start){
            cout<<"---------------------------------"<<endl;
            cout<<"start: "<<start<<" end:"<<end<<endl;
            cout<<"subarr: ";
            for(int i= start;i<=end;i++){
                cout<<nums[i]<<" ";
            }
            cout<<endl;
            cout<<"arr: ";
            for(int i= 0;i<nums.size();i++){
                cout<<nums[i]<<" ";
            }
            cout<<endl;

            cout<<"---------------------------------"<<endl;
        }


        if(start<end){
            int piv = partion(nums, start, end);
            quickS(nums,start,piv-1);
            quickS(nums,piv+1,end);
        }
    }

    int partion(vector<int>& nums, int start, int end){
        int piv = nums[start];
        int i = start;
        int j = end;
        while(i<j){
            while(i<j && piv<=nums[j]) {
                j--;
            }
            while(i<j && piv>=nums[i]){
                i++;
            }

            if(i<j){
                swap(nums, i, j);
            }

        }
        swap(nums, start, i);
        return i;
    }

    void swap(vector<int>& nums ,int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

};

int main(){
    vector<int> num= {0,0,1,2,1,2,0};
    Solution().sortColors(num);
}