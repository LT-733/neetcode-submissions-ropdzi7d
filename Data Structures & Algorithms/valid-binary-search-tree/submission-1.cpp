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
    vector<int> vals;
    void getVals(TreeNode* root){
        if(!root) return;
        getVals(root->left);
        vals.push_back(root->val);
        getVals(root->right);
    }
    bool isValidBST(TreeNode* root) {
        getVals(root);
        for(int i = 0; i < vals.size()-1; ++i){
            if(vals[i] >= vals[i+1]) return false;
        }return true;
    }
};
