//
// Created by Frank Lin on 20/8/21.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int cc =0;
    int InversePairs(vector<int> data) {
        int n = data.size();
        mergeSort(data,0,n-1);
        return cc;

    }

    void mergeSort(vector<int> &data, int l, int r){
        if(l>=r){
            return ;
        }
        int mid = l+(r-l)/2;

        mergeSort(data, l, mid);
        mergeSort(data, mid+1, r);

        merge(data,l,mid,r);



    }

    void merge(vector<int> &data, int l, int mid ,int r){
        vector<int> temp(r-l+1);

        int i = l, j = mid+1,k=0;
        while(i<=mid && j<=r){
            if(data[i]<=data[j]){
                temp[k] = data[i];
                k++;
                i++;
            }else{
                temp[k] = data[j];
                k++;
                j++;
            }
        }
        while(i<=mid){
            temp[k] = data[i];
            i++;k++;
        }
        while(j<=r){
            temp[k] = data[j];
            j++;k++;
        }

        for(int i =0;i<=mid;i++){
            if(temp[mid+1]>temp[i]){
                cc++;
            }else{
                break;
            }
        }

        for(int i = l ;i<=r;i++){
            data[i] = temp[i-l];
        }
    }
};


int main(){
    vector<int>v1{1,2,3};
    int n=v1.size();
//    Solution().mergeSort(v1, 0, n-1);
    int k = Solution().InversePairs(v1);
    cout<<k;
//    for(auto num:v1){
//        cout<<num<<" ";
//    }
    return 0;
}
