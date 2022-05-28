//
// Created by Frank Lin on 3/11/21.
//
//
//#include <iostream>
//#include <cmath>
//#include <deque>
//using namespace std;
//
////
////
////void iter(){
////    cout<<endl;
////    cout<< "start iteration "<<endl;
////    int a= 0;
////    int b = 200;
////    cout << "a address: "<<  &a<<" b address:"<<&b <<endl;
////    cout << "address gap: "<< sizeof(&a-&b )<<endl;
////    cout<< "end iteration "<<endl;
////
////}
////int main(){
////    iter();
////    iter();
////    return 0;
////}
//
//
//
//#include <iostream>
//#include <cmath>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int sum;
//    vector<vector<int>> ans;
//    vector<int> cur;
//    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//        function(candidates,target, 0);
//        return ans;
//
//    }
//    void function(vector<int>& candidates, int target, int index){
//        if(sum > target){
//            return;
//        } else if (sum == target){
//            ans.push_back(cur);
//        }else{
//            for(int i = index ;i<candidates.size();i++){
//                sum+=candidates[i];
//                cur.push_back(candidates[i]);
//                function(candidates, target,i);
//                sum-=candidates[i];
//                cur.pop_back();
//            }
//        }
//
//    }
//};


#include <vector>
#include <iostream>
#include <string>
using namespace std;

int solution(int A, int B) {
    // write your code in C++14 (g++ 6.2.0)
//    string a = to_string(A);
//    string b = to_string(B);
//    vector<char>ans(a.size()+b.size(),0);
//    int n = a.size();
//    int m = b.size();
//    for(int i =0;i <n;i++){
//        for(int j=0;j<m;j++){
//            ans[i+j+1] = (a[i]-'0')*(b[j]-'0');
//        }
//    }
//
//    for(int i = m+n+1; i>=0;i--){
//        if(ans[i]>9){
//            ans[i-1]+=ans[i]/10;
//            ans[i] = ans[i]%10;
//        }
//    }

    long long  total = A * B;
    int ans = 0;
    while (total != 0) {
        int temp = total % 2;
        if (temp == 1) {
            ans++;
        }
        total /= 2;
    }
    return ans;
}
int main(){
    int a= 2;
    int b = 1;
    solution(a,b);
}

