//
// Created by Frank Lin on 29/10/21.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> swap(vector<int>& array, int i, int j){
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
    return array;

}

vector<int> reOrderArrayTwo(vector<int>& array) {
    // write code here
    int i =0, j= array.size()-1;
    while(1){
        //求偶
        while(array[i]%2 !=0){
            i++;
        }
        //找奇
        while(array[j]%2 !=1){
            j--;
        }
        if(i<=j){
            //交换
            swap(array, i, j);
        } else{
            break;
        }


    }
    return array;
}

//vector<int> swap(vector<int>& array, int i, int j){
//    int temp = array[i];
//    array[i] = array[j];
//    array[j] = temp;
//    return array;
//
//}

int main()
{
    int arr[] = {1,2,3,4,5,6,7};
    int size = sizeof(arr)/ sizeof(arr[0]);

    vector<int> v(arr, arr+size);
    vector<int> v1;
    v1 = reOrderArrayTwo(v);
    return 0;
}