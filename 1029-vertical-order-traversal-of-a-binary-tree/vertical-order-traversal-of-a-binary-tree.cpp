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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int,int>>> mp;  //c -> r, val

        stack<pair<TreeNode* , pair<int,int>>> st;  //NODE , r, c

        st.push({root, {0,0}});

        while(!st.empty()){
            TreeNode* node = st.top().first;
            int r = st.top().second.first;
            int c = st.top().second.second;
            st.pop();
            mp[c].push_back({r,node->val});

            if(node ->left) st.push({node->left,{r+1, c - 1}});

            if(node->right) st.push({node->right, {r+1 , c+1}});
        }

        vector<vector<int>> ans;

        for(auto& it: mp){

            int key = it.first;
            vector<int> temp;
            sort(begin(it.second), end(it.second));
            for(auto& x : it.second){
                int r = x.first;
                int val = x.second;
                temp.push_back(val);
            }

            ans.push_back(temp);

        }

        return ans;

    }
};