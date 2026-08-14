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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }

        queue<pair<TreeNode*, long long>> q;
        long long maxwidth = 0;
        q.push({root, 1});
        while(!q.empty()){
            int size = q.size();
            long long first = q.front().second;
            long long last = q.back().second;
            maxwidth = max(maxwidth, abs(last - first + 1));
            while(size--){
                auto node= q.front().first;
                long long index = q.front().second - first;
                q.pop();
                
                if(node->left) q.push({node->left, 2*index});
                if(node->right) q.push({node->right, 2*index + 1});
            }
        }

        

        return maxwidth;

    }
};