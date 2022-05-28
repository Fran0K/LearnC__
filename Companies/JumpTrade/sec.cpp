//
// Created by Frank Lin on 25/4/2022.
//
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

bool isLeapYear(int year){
    if(year%400 == 0){
        return true;
    }
    if(year % 100 == 0){
        return false;
    }
    if(year %4 == 0){
        return true;
    }
    return false;
}

int solution(int Y, string &A, string &B, string &W) {
    // write your code in C++14 (g++ 6.2.0)
    //is leneYear
    vector<string>month={"January", "February", "March",
                         "April", "May","June", "July",
                         "August", "September", "October",
                         "November","December"};

    unordered_map<string,int>weeks={{"Monday",0},{"Tuesday",1},{"Wednesday",2},
                                    {"Thursday",3},{"Friday",4},{"Saturday",5},
                                    {"Sunday",6}};
    vector<int>days;

    if(isLeapYear(Y)){
        //leapYear
        days={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    }else{
        days={31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    }
    //
    int startIndex =0;
    int endIndex = 0;
    for(int i =0; i<month.size(); i++){
        if(month[i] == A){
            startIndex =i;
        }
        if(month[i]==B){
            endIndex=i;
        }
    }
    int sday=0;
    for(int i =0;i<startIndex;i++){
        sday+=days[i];
    }
    sday+=1;

    int eday = 0;
    for(int i =0;i<=endIndex;i++){
        eday+=days[i];
    }


    int startWeek = weeks.find(W)->second+1;

    if(startWeek!=1){
        sday+=(7-startWeek);
    }

    if(startWeek!=7){
        eday = eday-startWeek;

    }

    int ans = (eday-sday)/7;
    cout<<ans;
    return ans;
}

int main(){
    int Y=2014;
    string A="April";
    string B="May";
    string W="Wednesday";
    solution(Y,A,B,W);

}
