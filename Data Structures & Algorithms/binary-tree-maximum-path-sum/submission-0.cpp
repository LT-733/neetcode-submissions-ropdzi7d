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
    int maxPathSum(TreeNode* root, int& ans) {
        if(!root) return 0;
        int leftVal = max(maxPathSum(root->left, ans), 0);
        int rightVal = max(maxPathSum(root->right, ans), 0);
        ans = max(ans, root->val + leftVal + rightVal);
        
        return root->val + max(leftVal, rightVal);
    }
    int maxPathSum(TreeNode* root){
        int cur = root->val;
        maxPathSum(root, cur);
        return cur;
    }
};
