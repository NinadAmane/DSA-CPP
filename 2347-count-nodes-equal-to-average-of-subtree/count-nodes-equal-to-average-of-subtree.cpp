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
    int ans = 0;
    int count(TreeNode* root){
        if(!root) return 0;

        int left = count(root->left);
        int right = count(root->right);

        return 1 + left + right;
    }
    int summ(TreeNode* root ){
        if(!root) return 0;

        int sum = root->val;
        int left = summ(root->left);
        int right = summ(root->right);
        return sum + left + right;
    }
    int averageOfSubtree(TreeNode* root) {
        if(!root) return 0;

        int sumofnodes = summ(root);
        int countofnodes = count(root);

        int average = sumofnodes / countofnodes;
        if(average == root->val) ans++;
        if(root->left)  averageOfSubtree(root->left);
        averageOfSubtree(root->right);


        return ans;

    }
};