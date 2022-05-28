//
// Created by Frank Lin on 17/2/22.
//

#include <iostream>
#include <vector>
using namespace std;

class solu{
public:
    void merge(vector<int> &arr, int begin, int mid, int end){
        int i = begin;
        int j = mid+1;
        int k = 0;
        vector<int> temp(end-begin+1, 0);

        while(i<=mid && j<=end){
            if(arr[i]<=arr[j]){
                temp[k++] = arr[i++];
            } else{
                temp[k++] = arr[j++];
            }
        }
        while(i<=mid){
            temp[k++] = arr[i++];
        }
        while(j<=end){
            temp[k++] = arr[j++];
        }
        int x = begin;
        for(int i =0;i<temp.size(); i++){
            arr[x] = temp[i];
            x++;
        }
    }

    void mergeSort(vector<int> &arr, int begin, int end){
        if(begin<end){
            int mid = begin + (end - begin)/2;
            mergeSort(arr, begin, mid);
            mergeSort(arr, mid+1, end);
            merge(arr,begin,mid,end);
        }
    }
};





int main(){
    vector<int> arr {-74,48,-20,2,10,-84,-5,-9,11,-24,-91,2,-71,64,63,80,28,-30,-58,-11,-44,-87,-22,54,-74,-10,-55,-28,-46,29,10,50,-72,34,26,25,8,51,13,30,35,-8,50,65,-6,16,-2,21,-78,35,-13,14,23,-3,26,-90,86,25,-56,91,-13,92,-25,37,57,-20,-69,98,95,45,47,29,86,-28,73,-44,-46,65,-84,-96,-24,-12,72,-68,93,57,92,52,-45,-2,85,-63,56,55,12,-85,77,-39};
    int n = arr.size()-1;
    solu().mergeSort(arr,0, n);
    for(auto num:arr){
        cout<<num<<" ";
    }
}