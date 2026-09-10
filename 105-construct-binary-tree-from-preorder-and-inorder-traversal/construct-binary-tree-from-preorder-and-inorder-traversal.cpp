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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int left, int right, int& ind){
        if(left > right) return NULL;

        int pivot = left;
        while(inorder[pivot] != preorder[ind]) pivot++;

        ind++;
        TreeNode* newNode = new TreeNode(inorder[pivot]);
        newNode->left = build(preorder,inorder,left, pivot - 1, ind);
        newNode->right = build(preorder,inorder, pivot+1, right, ind);

        return newNode;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        
        int rootidx = 0;

        auto it = find(inorder.begin(), inorder.end(), preorder[rootidx]);
        int pivot = it - inorder.begin();

        return build(preorder,inorder, 0,n-1, rootidx);
    }
};