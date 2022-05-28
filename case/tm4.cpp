//
// Created by Frank Lin on 02/04/2022.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
int minCount(int n, vector<int>& nums){
    int a=0,b=0,c=0;
    sort(nums.begin(), nums.end());
    for(int i =n-1; i>=0;i-=3){
        a+=nums[i];
        if(i-1>=0){
            b+=nums[i-1];
        }
        if(i-2>=0){
            c+=nums[i-2];
        }
    }
    return max(c, max(b,c));
    }
};

int main(){
    //int n ;
    //cin>>n;
    //vector<int> nums(n,0);
//    for(int i =0;i<n;i++){
//        int a =0;
//        nums.push_back(cin>>a);
//    }
    int n=7;
    vector<int> nums{5,4,6,6,8,3,7};

    Solution().minCount(n, nums);
}