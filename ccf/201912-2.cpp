//
// Created by Frank Lin on 14/9/21.
//

#include <iostream>
#include <vector>

const int N = 1e3+2;
int num[N] = {0};

int grade[5] ={0};

using namespace std;

vector<pair<int, int>> loca;
bool isTrash(int x, int y, int n){
    int score=0;
    for (int i = 0; i <n ; ++i) {
        if(loca[i].first ==x -1 && loca[i].second == y){
            score++;
        }if(loca[i].first == x+1 && loca[i].second == y){
            score++;
        }if(loca[i].first == x && loca[i].second == y-1){
            score++;
        }if(loca[i].first == x && loca[i].second == y+1){
            score++;
        }
    }
    if (score == 4){
        return true;
    }
    return false;
}

int stat(int x, int y, int n){
    int score=0;
    for (int i = 0; i <n ; ++i) {
        if(loca[i].first == x - 1 && loca[i].second == y-1){
            score++;
        }if(loca[i].first == x+1 && loca[i].second == y+1){
            score++;
        }if(loca[i].first == x+1 && loca[i].second == y-1){
            score++;
        }if(loca[i].first == x-1 && loca[i].second == y+1){
            score++;
        }
    }
    return score;
}

int main(){
    int n;
    cin >> n;


    for (int i = 0,x, y; i <n ; ++i) {
        cin >> x >> y;
        loca.push_back(make_pair(x,y));
    }

    for (int j = 0,x,y; j <n ; ++j) {
        x = loca[j].first;
        y = loca[j].second;
        if(isTrash(x,y, n)){
            grade[stat(x,y,n)]++;
        }
    }
    for (int k = 0; k <5 ; ++k) {
        cout<<grade[k]<<endl;
    }
    return 0;
}