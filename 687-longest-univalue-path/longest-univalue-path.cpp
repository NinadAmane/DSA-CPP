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
    int maxunivaluepath(TreeNode* root, int&maxi){
        if(root==NULL) return 0;

        int left = maxunivaluepath(root->left, maxi);
        int right = maxunivaluepath(root->right, maxi);

        int countleft = 0;
        int countright = 0;

        if(root->left && root->left->val == root->val){
            countleft = left + 1;
        }

        if(root->right && root->right->val == root->val){
            countright = right + 1;
        }
        
        maxi = max(maxi, countright + countleft);
        return max(countright, countleft);

    }
    int longestUnivaluePath(TreeNode* root) {
        if(root == NULL) return 0;
        int count = 0;
        int maxi = INT_MIN;
        maxunivaluepath(root, maxi);

        return maxi;
    }
};