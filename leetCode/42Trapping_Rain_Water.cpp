//
// Created by Frank Lin on 5/2/22.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int n = height.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        //left
        left[0]=height[0];
        right[n-1]=height[n-1];
        for(int i =1  ;i<n; i++){
            if(left[i-1]>height[i]){
                left[i]=left[i-1];
            }else{
                left[i]=height[i];
            }
        }

        //right
        for(int i = n-2 ;i>=0; i--){
            if(right[i+1]>height[i]){
                right[i] = right[i+1];
            }else{
                right[i]=height[i];
            }
        }

        for(int i=0;i<n;i++){
            int temp = min(left[i], right[i])-height[i];
            if(temp >= 0){
                ans+=temp;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums{0,1,0,2,1,0,1,3,2,1,2,1};
    int k = Solution().trap(nums);

}