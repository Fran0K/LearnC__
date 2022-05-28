//
// Created by Frank Lin on 15/12/21.
//
#include <vector>
#include <list>
using namespace std;
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int i = 0;
    int valley = prices[0];
    int peak = prices[0];
    int maxprofit = 0;
    while (i < n - 1) {
        while (i < n - 1 && prices[i] >= prices[i + 1]) {
            i++;
        }
        valley = prices[i];
        while (i < n - 1 && valley >= prices[i]) {
            i++;
        }
        peak = prices[i];
        i++;
        maxprofit += peak - valley;
    }
    return maxprofit;
}
int main(){
    vector<int> v1 = {1,2,3,0,2};
    maxProfit(v1);
    return 0;
}