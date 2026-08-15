/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(root == NULL){
            return {};
        }

        unordered_map<TreeNode*, TreeNode*> parents; //parents mapping
        stack<TreeNode*> st;
        parents[root] = NULL;
        st.push(root);

        while(!st.empty()){
            auto node = st.top();
            st.pop();
            
            if(node->left){
                st.push(node->left);
                parents[node->left] = node;
            }
            if(node->right){
                st.push(node->right);
                parents[node->right] = node;
            }
        }
        

        queue<TreeNode*> q;
        unordered_set<TreeNode*> vis;
        q.push(target);
        vis.insert(target);
        int distance = 0;

        while(!q.empty()){
            int size = q.size();
            if(distance == k){
                break;
            }

            while(size--){
                auto node = q.front();
                q.pop();
                if(node->left && !vis.count(node->left)){
                    q.push(node->left);
                    vis.insert(node->left);
                }
                if(node->right && !vis.count(node->right)){
                    q.push(node->right);
                    vis.insert(node->right);
                }
                if(parents[node] && !vis.count(parents[node])){
                    q.push(parents[node]);
                    vis.insert(parents[node]);
                }

            } 
            distance++;
        }
        if(distance != k) return {};
        cout << distance << endl;
        vector<int> ans;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            ans.push_back(node->val);
        }
        return ans;

    }
};