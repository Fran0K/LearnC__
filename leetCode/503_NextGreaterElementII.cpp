//
// Created by Frank Lin on 1/12/21.
//
#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;
//vector<int> nextGreaterElements(vector<int>& nums) {
//    stack<int> s;
//    int n = nums.size();
//    vector<int> next(n, -1);
//    for (int i = 0; i < 2 * n; i++) {
//            int num = nums[i % n];
//            while (!s.empty() && nums[s.top()] < num) {
//                next[s.top()] = num;
//                s.pop();
//            }
//            if (i < n) s.push(i);
//        }
//        return next;
//}

vector<int> nextGreaterElements(vector<int>& nums) {

    unordered_map<int, int>mp;
    int n = nums.size();
    vector<int> ans(2*n,0);
    for(int i =0 ;i<2*n;i++){
        ans[i] = nums[i%n];
    }

    int m = ans.size();
    stack<int> st;
    for(int i =m-1 ;i>=0;i--){
        while(!st.empty() && ans[i]>=ans[st.top()]){
            st.pop();
        }
        if(!st.empty()){
            mp.insert(make_pair(ans[i], ans[st.top()]));
        }
        st.push(i);
    }

    vector<int> temp;
    for(int i =0; i<n; i++){
        auto iter = mp.find(nums[i]);
        if(iter != mp.end()){
            temp.push_back(iter->second);
        }else{
            temp.push_back(-1);
        }
    }
    return temp;

}

int main(){
    vector<int> nums2 = {100,1,11,1,120,111,123,1,-1,-100};
    nextGreaterElements(nums2);
    return 0;
}
