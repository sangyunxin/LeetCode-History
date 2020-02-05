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
    vector<vector<int>> ret;

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        helper(root, sum, {});
        return ret;
    }

    void helper(TreeNode* root, int sum, vector<int> cur){
        if(!root)
            return;

        if(!root->left && !root->right){
            if(root->val == sum){
                cur.push_back(root->val);
                ret.push_back(cur);
            }
            return;
        }

        cur.push_back(root->val);
        helper(root->left, sum-root->val, cur);
        helper(root->right, sum-root->val, cur);
    }
};