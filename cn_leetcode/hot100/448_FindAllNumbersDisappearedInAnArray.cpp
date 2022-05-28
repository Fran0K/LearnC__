//
// Created by Frank Lin on 28/2/22.
//

//using namespace std;
//
//#include <vector>
//vector<int> findDisappearedNumbers(vector<int>& nums) {
//    int n = nums.size();
//    vector<int> a(n+1,0);
//    for(int i =0;i<n; i++){
//        a[nums[i]]+=1;
//    }
//    vector<int> ans;
//    for(int i =1 ;i<=n;i++){
//        if(a[i]==0){
//            ans.push_back(i);
//        }
//    }
//    return ans;
//}
//int main(){
//    vector<int> a={1,1};
//    findDisappearedNumbers(a);
//}
//void moveZeroes(vector<int>& nums) {
//    int n =nums.size();
//    vector<int> ans(n,0);
//    int j =0;
//    for(int i =0;i<n;i++){
//        if(nums[i]!=0){
//            ans[j++]=nums[i];
//        }
//    }
//    for(int i =0;i<n;i++){
//        nums[i] = ans[i];
//    }
//}
//int main(){
//    vector<int> a={0,1,0,3,12};
//    moveZeroes(a);
//}
using namespace std;

#include <unordered_map>
#include <vector>
int majorityElement(vector<int>& nums) {
    unordered_map<int, int> mp;
    int mid = nums.size()/2;
    for(auto num: nums){
        auto it = mp.find(num);
        if(it!=mp.end()){
            it->second++;
            if(it->second>mid){
                return it->first;
            }
        }else{
            mp.insert(make_pair(num,1));
        }
    }
    return 0;

}

int main(){
    vector<int> temp = {3,2,3};
    int k= majorityElement(temp);
}