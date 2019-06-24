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
    int res;

    int maxDepth(TreeNode* root) {
        res = 0;
        if(root != NULL)
            depth(root, 0);
        return res;
    }

    void depth(TreeNode* root, int d){
        d++;
        if(root->left == NULL && root->right == NULL){
            res = max(d, res);
            return;
        }
        if(root->left != NULL)
            depth(root->left, d);
        if(root->right != NULL)
            depth(root->right, d);
    }
};