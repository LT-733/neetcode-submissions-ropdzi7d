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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& res) {
        if(!root) return nullptr;
        if(root == q or root == p){
            TreeNode* leftRes = lowestCommonAncestor(root->left, p, q, res);
            TreeNode* rightRes = lowestCommonAncestor(root->right, p, q, res);
            if((leftRes and !rightRes) or (rightRes and !leftRes)) {
                res = root;
                return nullptr;
            }// if we found both on this one, then we are done and nullptr it back
            else if(!leftRes and !rightRes){
                return root;
            }// this is the only one I found, then we punch it back up
        }else{
            TreeNode* leftRes = lowestCommonAncestor(root->left, p, q, res);
            TreeNode* rightRes = lowestCommonAncestor(root->right, p, q, res);
            if((leftRes and !rightRes) or (rightRes and !leftRes)){
                return root;
            }// we found one of them and we return root
            else if(!leftRes and !rightRes){
                return nullptr;
            }// found nothing, this route is a no go
            else if(rightRes and leftRes){
                res = root;
                return nullptr;
            }// we found both on this one, we are done and nullptr it back
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        TreeNode* res = nullptr;
        lowestCommonAncestor(root, p, q, res);
        return res;
    }
};
