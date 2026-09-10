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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd, unordered_map<int,int>& mp){
        if(preStart > preEnd || inStart > inEnd) return NULL;

        TreeNode* node = new TreeNode(preorder[preStart]);

        int pivot = mp[node->val];
        int left = pivot - inStart;


        node->left = build(preorder, inorder, preStart+1, preStart + left, inStart, pivot-1, mp);

        node->right = build(preorder, inorder, preStart+1+left, preEnd, pivot+1 , inEnd, mp);

        return node;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[inorder[i]] = i;
        }
        TreeNode* root = build(preorder, inorder, 0,n-1, 0,n-1,mp);
        return root;
    }
};