/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return helper(root->left, root->right);
    }

    bool helper(TreeNode* ln, TreeNode* rn){
        if(ln == NULL && rn == NULL)
            return true;
        if(ln == NULL || rn == NULL || ln->val != rn->val)
            return false;
        return helper(ln->left, rn->right) && helper(ln->right, rn->left);
    }
};