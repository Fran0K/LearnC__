//
// Created by Frank Lin on 8/2/22.
//

#include <iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    //TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* Node(int key){
    TreeNode *temp = new TreeNode;
    temp->val = key;
    temp->left = temp->right = NULL;
    return temp;
}

//Node* newNode(int val){
//    Node *temp = new Node;
//    temp->val = val;
//    temp->left = temp->right=NULL;
//    return temp;
//}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q){
            return root;
        }
        cout<<root->val<<" -> ";
        TreeNode* l = lowestCommonAncestor(root->left, p,q);
        TreeNode* r = lowestCommonAncestor(root->right, p,q);

        if(l == NULL){
            return r;
        }
        if(r== NULL){
            return l;
        }
        return root;

    }
};

int main(){
    TreeNode* root = Node(3);
    root->left=Node(5);
    TreeNode* p = root->left;

    root->right=Node(1);

    root->left->left = Node(6);
    root->left->right = Node(2);
    TreeNode* q = root->left->right;
    root->left->right->left = Node(7);
    root->left->right->right = Node(4);

    root->right->left=Node(0);
    root->right->right=Node(8);

    TreeNode* ans = Solution().lowestCommonAncestor(root,p,q);
    cout<<endl;
    cout<<"--------ans-----------"<<endl;
    cout<<ans->val<<endl;


}


