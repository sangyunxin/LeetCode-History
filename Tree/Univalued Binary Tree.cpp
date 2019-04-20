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
    bool isUnivalTree(TreeNode* root) {
        int val = root->val;
        return preOrder(root, val);
    }

    bool preOrder(TreeNode* root, int val){
        if(root == NULL)
            return true;
        if(root->val != val)
            return false;
        return preOrder(root->left, val) && preOrder(root->right, val);
    }
};