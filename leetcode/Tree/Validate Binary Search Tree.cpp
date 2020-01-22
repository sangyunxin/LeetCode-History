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
    bool isValidBST(TreeNode* root) {
        return helper(root, LLONG_MAX, LLONG_MIN);
    }

    bool helper(TreeNode* root, long long maxv, long long minv){
        if(root == NULL)
            return true;
        if(root->val >= maxv || root->val <= minv)
            return false;
        return helper(root->left, root->val, minv) && helper(root->right, maxv, root->val);
    }
};