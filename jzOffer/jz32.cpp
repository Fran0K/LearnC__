//
// Created by Frank Lin on 17/9/21.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string PrintMinNumber(vector<int> numbers) {
    long min = 0;
    sort(numbers.begin(), numbers.end());
    long temp1 =stol(to_string(numbers[0]).append(to_string(numbers[1]))) ;
    long temp2 =stol(to_string(numbers[1]).append(to_string(numbers[0])));
    if(temp1>temp2){
        min = temp2;
    }else{
        min = temp1;
    }
    for(int i = 2 ;i < numbers.size(); i++){
        long temp1 = stol(to_string(min).append(to_string(numbers[i])));
        long temp2 = stol(to_string(numbers[i]).append(to_string(min)));
        if(temp1>temp2){
            min = temp2;
        }else{
            min = temp1;
        }
    }
    string ans = to_string(min);
    return ans;
}
int main(){
    vector<int> v;
    v.push_back(3334);
    v.push_back(3);
    v.push_back(3333332);
    string s = PrintMinNumber(v);
    cout<< s;

}
