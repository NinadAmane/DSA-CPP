/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "null,";
        string ans = "";
        ans += to_string(root->val);
        ans += ',';
        ans += serialize(root->left);
        ans += serialize(root->right);

        return ans; 

    }

    // Decodes your encoded data to tree.
    TreeNode* build(vector<string>& tokens, int& idx){
        int n = tokens.size();
        if(idx >= n) return NULL;

        if(tokens[idx] == "null"){
            idx++;
            return nullptr;
        } 

        TreeNode* root = new TreeNode(stoi(tokens[idx++]));
        root->left = build(tokens, idx);
        root->right = build(tokens,idx);
        return root;
    }
    TreeNode* deserialize(string data) {
        if(data.empty() || data == "null,") return NULL;
        int n = data.size();

        vector<string> tokens;
        string curr = "";
        for(char c : data){
            if(c == ','){
                tokens.push_back(curr);
                curr = "";
            }
            else{
                curr += c;
            }
        }

        for(auto c : tokens){
            cout << c << endl;
        }
        int idx = 0;
        TreeNode* root = build(tokens, idx);

        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));