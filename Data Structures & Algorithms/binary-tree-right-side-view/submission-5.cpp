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
    vector<int> res;
    vector<int> rightSideView(TreeNode* root) {
        rightside(root, 0);
        return res;
    }
    void rightside(TreeNode* root, int depth){
        if(!root) return;
        if(res.size() == depth) res.push_back(root->val);
        rightside(root->right, depth+1);
        rightside(root->left, depth+1);
    }
};
