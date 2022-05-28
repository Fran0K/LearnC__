//
// Created by Frank Lin on 29/4/2022.
//

#include <vector>
#include <unordered_map>
using namespace std;

/*
 * Complete the 'deleteProducts' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY ids
 *  2. INTEGER m
 */

int deleteProducts(vector<int> ids, int m) {
    unordered_map<int, int>mp;
    for(auto x:ids ){
        mp[x]++;
    }
    int count =0;
    vector<pair<int,int>>ans;
    for(auto x: mp){
        ans.emplace_back(make_pair(x.second, x.first));
    }
    int n = ans.size();
    sort(ans.begin(), ans.end());

    for(auto x:ans){
        if(x.first<=m){
            m-=x.first;
            count++;
        }
        else{
            return n-count;
        }
    }
    return n-count;

}

int main()
{
    vector<int> ans ={1, 1, 5, 5};
    deleteProducts(ans,2);

}

