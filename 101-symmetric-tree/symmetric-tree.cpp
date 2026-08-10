/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invert(TreeNode* root){
        if(root == NULL) return NULL;
        invert(root->left);
        invert(root->right);
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        return root;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;

        if((p == NULL && q != NULL) || (p!= NULL && q == NULL)) return false;

        if(p->val != q->val) return false;
        

        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);

        return left && right;
    } 
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        
        TreeNode* left = invert(root->left);


        return isSameTree(left, root->right);
        

    }
};