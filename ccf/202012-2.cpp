//
// Created by Frank Lin on 8/9/21.
//

//期末预测之最佳阈值
//

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
const int N=1e5+2;
//int sum[N] = {0};
//
//int maxC=0;



set<int> s;

int main(){
    int res = 0;
    int sum[N] = {0};
    int maxC=0;
    int m;
    cin >> m;
    vector<pair<int, int>>v;
    for (int i = 0; i <m ; ++i) {
        int v1,v2;
        cin >> v1 >> v2;
        v.push_back(make_pair(v1,v2));
    }

    sort(v.begin(), v.end());

    for (int k = 0; k <m ; ++k) {
        if(k == 0){sum[k] = v[k].second;}
        else{sum[k] = sum[k-1] + v[k].second;}
    }
    for (int j = 0; j <m ; ++j){
        if(s.count(v[j].first)){
            continue;
        } else{
            s.insert(v[j].first);
            int cou1 = sum[m-1] - sum[j];
            int cou0 = j - sum[j-1];
            int total = cou1 + cou0;
            if(total >= maxC){
                maxC = total;
                res = v[j].first;
            }

        }
    }
    cout << res;
    return 0;

}