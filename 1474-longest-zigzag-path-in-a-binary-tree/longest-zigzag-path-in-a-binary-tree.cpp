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
    int maxi= 0;
    void dfs(TreeNode* root, int count, bool turn){ //returns the longest zigzag route
        if(root== NULL) return ;
        
        maxi = max(count, maxi);
        if(turn){
            if(root->left){
                // count = 1;
                dfs(root->left, 1, turn);
            }
            if(root->right){
                dfs(root->right, count + 1, !turn);
            }
        }
        else{
            if(root->left){
                dfs(root->left, count + 1, !turn);
            }
            if(root->right){
                // count = 1;
                dfs(root->right, 1, turn);
            }
        }

        return;
    }
    //true = left
    //false = right

    int longestZigZag(TreeNode* root) {
        if(root == NULL) return 0;
        
        int count = 1;

        
        if(root->left) dfs(root->left, count , true);
        
        if(root->right) dfs(root->right,count,false);
        // cout << (count) << endl;
        return maxi;
        





        // stack<pair<TreeNode*, pair<int,bool>>> st; //node, count , // lastMove = true  -> previous move was LEFT
        //                                                             // lastMove = false -> previous move was RIGHT
        // int maxi = 0;

        // if(root->left) st.push({root->left, {1, true}});
        // if(root->right) st.push({root->right, {1, false}});

        // while(!st.empty()){
        //     TreeNode* node = st.top().first;
        //     int count = st.top().second.first;
        //     bool direction = st.top().second.second;
        //     st.pop();
        //     maxi = max(count , maxi);
        //     if(direction){
        //         if(node->left){
                    
        //             st.push({node->left, {1, direction}});
        //         }
        //         if(node->right){
        //             st.push({node->right, {count + 1, !direction}});
        //         }
        //     }
        //     else{
        //         if(node->left){
        //             st.push({node->left, {count +1 , !direction}});
        //         }
        //         if(node->right){
                    
        //             st.push({node->right, {1, direction}});
        //         }
        //     }
        // }

        // return maxi;
    }
};