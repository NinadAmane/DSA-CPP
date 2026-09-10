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
    unordered_map<int,int> mp;
    TreeNode* build(vector<int>& postorder, int inL, int inR, int& postind){
        if(inL > inR) return NULL;

        int val = postorder[postind--];
        TreeNode* node = new TreeNode(val);

        int pivot = mp[val];
        node->right = build(postorder,pivot+1, inR, postind);
        node->left = build(postorder, inL, pivot-1, postind);

        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();

        for(int i=0;i<n;i++){
            mp[inorder[i]] = i;
        }
        int postind = n-1;
        TreeNode* root = build(postorder, 0, n - 1,postind);
        return root;
    }
};