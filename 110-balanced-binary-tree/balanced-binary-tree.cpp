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
    int maxD(TreeNode* root){
        if(root == NULL) return 0;
        int count = 0;
        count = max(maxD(root->left), maxD(root->right)) + 1;
        return count;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL ) return true;
        int left = maxD(root->left);
        int right = maxD(root->right);

        bool ans = abs(left - right) <= 1;
        return (ans && isBalanced(root->left) && isBalanced(root->right));
    }
};