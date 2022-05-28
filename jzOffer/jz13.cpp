//
// Created by Frank Lin on 9/9/21.
//
#include <vector>
using namespace std;

vector<int> reOrderArray(vector<int>& array) {
    // write code here
    int oPtr = 0;
    int jPtr = array.size() / 2;
    int oFlag = 1;
    int jFlag = 1;
    while (oFlag ==1 && jFlag==1) {
        //前半段找偶数
        while (array[oPtr] % 2 != 0) {
            oPtr++;
            if (oPtr == int(array.size()/2)) {
                oFlag = 0;
            }
        }
            //后半段找奇数
        while (array[jPtr] % 2 != 1 ) {
            jPtr++;
            if (jPtr >= int(array.size())){
                jFlag = 0;
                jPtr = array.size()-1;
                break;
            }
        }
        if(jFlag != 0 && oFlag!=0 ){
            int temp = array[oPtr];
            array[oPtr] = array[jPtr];
            array[jPtr] = temp;
        }

    }

    return array;
}

int main(){
    vector<int> v;
    vector<int> v1;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    v1 = reOrderArray(v);
}