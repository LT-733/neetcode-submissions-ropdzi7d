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
private:
    int depth(TreeNode* root, bool& withinOne){
        if (!root) {
            if(withinOne) withinOne = true; // node is empty, the height is indeed within One
            return 0;
        }
        int leftheight = 1 + depth(root->left, withinOne);
        int rightheight = 1 + depth(root->right, withinOne);
        if(withinOne) withinOne = abs(leftheight - rightheight) <= 1;
        return max(leftheight, rightheight);
    }
public:
    bool isBalanced(TreeNode* root) {
        bool withinOne = true;
        depth(root, withinOne);
        return withinOne;
    }
};
