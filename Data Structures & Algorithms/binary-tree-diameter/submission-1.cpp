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
    int diameterOfBinaryTree(TreeNode* root, int& mx) {
        if(!root) return 0;
        int leftsum = diameterOfBinaryTree(root->left, mx);
        int rightsum = diameterOfBinaryTree(root->right, mx);
        int midsum = leftsum + rightsum;
        if(midsum > mx) mx = midsum;
        return 1 + max(leftsum, rightsum);
    }
    int diameterOfBinaryTree(TreeNode* root){
        int mx = 0;
        diameterOfBinaryTree(root, mx);
        return mx;
    }
};
