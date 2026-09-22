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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            if(!cur){
                s += "Null,";
                continue;
            }else{
                s += to_string(cur->val);
                s += ",";
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return s;
    }

    // TreeNode* buildTree(vector<string> nodes, int idx){
    //     TreeNode* cur = nullptr;
    //     if(idx < nodes.size()){
    //         if(nodes[idx] == "Null") return nullptr;
    //         cout<<stoi(nodes[idx])<<"\n";
    //         cur = new TreeNode(stoi(nodes[idx]));
    //         cur -> left = buildTree(nodes, 2*idx+1);
    //         cur -> right = buildTree(nodes, 2*idx+2);
    //     }
    //     return cur;
    // }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        vector<string> nodes;
        while(ss.good()){
            string sub;
            getline(ss, sub, ',');
            nodes.push_back(sub);
        }
        nodes.pop_back();
        if(nodes[0] == "Null") return nullptr;
        TreeNode* recovered = new TreeNode(stoi(nodes[0]));
        queue<TreeNode*> q;
        q.push(recovered);
        int idx = 0;
        while(++idx and idx < nodes.size()){
            TreeNode* cur = q.front();
            q.pop();
            if(nodes[idx] != "Null"){
                cur->left = new TreeNode(stoi(nodes[idx]));
                q.push(cur->left);
            }
            ++idx;
            if(nodes[idx] != "Null"){
                cur->right = new TreeNode(stoi(nodes[idx]));
                q.push(cur->right);
            }
        }
        return recovered;
    }
};
