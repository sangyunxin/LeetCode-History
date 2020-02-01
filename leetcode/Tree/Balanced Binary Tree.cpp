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
    bool flag;

    bool isBalanced(TreeNode* root) {
        flag = true;
        helper(root);
        return flag;
    }

    int helper(TreeNode* root) {
        if(!root)
            return 0;
        int left = 1 + helper(root->left);
        int right = 1 + helper(root->right);
        if(abs(left - right) > 1)
            flag = false;
        return max(left, right);
    }
};