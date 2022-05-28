//
// Created by Frank Lin on 30/11/21.
//


#include <vector>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;
//vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//    stack<int> s;
//    vector<int> v;
//    unordered_map<int,int> m;
//    for(int num: nums2){
//        while(!s.empty() && num < s.top() ){
//            s.pop();
//        }
//        if(!s.empty()){
//            m.insert(make_pair(num, s.top()));
//        }
//        s.push(num);
//    }
//    vector<int> ans;
//    for(int num: nums1){
//        auto iter = m.find(num);
//        if (iter!= m.end()){
//            int kk = iter->second;
//            ans.push_back(kk);
//
//        }else{
//            ans.push_back(-1);
//        }
//    }
//    return ans;
//}


#include <map>
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    vector<int> ans(n,-1);
    map<int, int> kk;

    for(int i=0;i<m;i++){
        kk.insert(make_pair(nums2[i],0));
    }

    stack<int> st;
    //monotone stack;
    for(int i =m-1; i>=0;i--){
        while(!st.empty() && nums2[st.top()] < nums2[i]){
            st.pop();
        }
        if(!st.empty()){
            auto iter = kk.find(nums2[i]);
            int g = nums2[st.top()];
            iter->second = g;
            // temp[i] = st.top() - i;
        }
        st.push(i);
    }

    for(int i =0 ;i<n;i++){
        auto iter = kk.find(nums1[i]);
        int g = iter->second;
        if(g!=0){
            ans[i] = g;
        }

    }
    return ans;
}


int main(){
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};
    nextGreaterElement(nums1, nums2);
    return 0;
}