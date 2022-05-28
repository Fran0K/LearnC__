//
// Created by Frank Lin on 16/04/2022.
//

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param preSlice int整型vector 先序遍历结果数组
     * @return TreeNode类
     */
    TreeNode* reConstructBST(vector<int>& preSlice) {
        // write code here
        TreeNode* root = preSlice

    }

    TreeNode* builtTree(vector<int>& preSlice, int start){
        TreeNode *root= preSlice[start];
        root.left = builtTree(preSlice, s)
    }
};