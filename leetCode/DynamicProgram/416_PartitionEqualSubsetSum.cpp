//
// Created by Frank Lin on 4/1/22.
//
#include <iostream>
#include <vector>
using namespace std;

bool canPartition(vector<int>& nums) {
    int sum=0;
    for(int num: nums){
        sum+=num;
    }
    //奇偶
    if(sum & 1){
        return false;
    }
    sum =sum/2;

    int n = nums.size();
    vector<vector<bool>> ans (n+1, vector<bool>( sum+1,false));
    for(int i =0; i<=n;i++){
        ans[i][0]= true;
    }

    for(int i = 1;i<=n;i++){
        for(int j =1; j<=sum;j++){
            if(j - nums[i-1]<0){
                ans[i][j] = ans[i-1][j];
            }else{
                bool no = ans[i-1][j];
                bool yes = ans[i-1][j-nums[i-1]];
                ans[i][j] =  no || yes;
            }
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;

    }
    return ans[n][sum];


}


int main(){
    vector<int> nums = {1,5,11,5};
    canPartition(nums);

}
