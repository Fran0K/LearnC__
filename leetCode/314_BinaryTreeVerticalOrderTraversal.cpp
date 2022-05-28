////
//// Created by Frank Lin on 4/5/2022.
////
//#include <vector>
//#include <unordered_map>
//#include <algorithm>
//using namespace std;
///**/
//
//struct TreeNode {
//      int val;
//      TreeNode *left;
//      TreeNode *right;
//      TreeNode() : val(0), left(nullptr), right(nullptr) {}
//      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  };
// /**/
//class Solution {
//public:
//    unordered_map<int, vector<pair<int, int>>>mp;
//    vector<vector<int>> verticalOrder(TreeNode* root) {
//        helper(root,0,0);
//        vector<vector<int>> ans;
//        if(root==nullptr){
//            return ans;
//        }
//        for(auto x: mp){
//            sort(x.second.begin(), x.second.end(), cmp);
//            vector<int>temp;
//            for(auto ee: x.second){
//                temp.push_back(ee);
//            }
//            ans.push_back(temp);
//        }
//        return ans;
//
//
//
//    }
//    static bool cmp(vector<pair<int, int>>&mp1, vector<pair<int, int>>&mp2){
//        return mp1[0]<mp2[0];
//    }
//
//    void helper(TreeNode* root, int r, int c){
//        if(root==nullptr){
//            return;
//        }
//        vector<pair<int,int>>a={r, root->val};
//        mp[c].push_back();
//        helper(root->left, r+1, c-1);
//        helper(root->right, r+1, c+1);
//    }
//};
//
//int main(){
//    TreeNode* root = new TreeNode(3);
//    TreeNode* l = new TreeNode(9);
//    TreeNode* r = new TreeNode(20);
//    r->left = new TreeNode(15);
//    r->right = new TreeNode(7);
//    root->left=l;
//    root->right = r;
//    Solution().verticalOrder(root);
//}