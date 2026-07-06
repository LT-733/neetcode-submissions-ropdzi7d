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
    void goodNodes(TreeNode* root, int& curmax, int& res){
        if(!root) return;
        if(root->val >= curmax) {
            ++res;
            curmax = root->val;
        }
        int oldmax = curmax;
        cout<<"curmax: "<<curmax<<endl;
        goodNodes(root->left, curmax, res);
        cout<<"curmax after one dfs stem: "<<curmax<<endl;
        curmax = oldmax;
        cout<<"curmax reset to the prior max"<<endl;
        goodNodes(root->right, curmax, res);
    }
    int goodNodes(TreeNode* root) {
        int result = 0;
        goodNodes(root, root->val, result);
        return result;
    }
};
