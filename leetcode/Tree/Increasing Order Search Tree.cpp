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
    TreeNode* increasingBST(TreeNode* root) {
        if(root == NULL)
            return NULL;
        vector<int> vals;
        inOrder(root, vals);
        TreeNode* res = new TreeNode(vals[0]);
        TreeNode* p = res;
        for(int i = 1; i < vals.size(); ++i){
            p->right = new TreeNode(vals[i]);
            p = p->right;
        }
        return res;
    }

    void inOrder(TreeNode* root, vector<int>& vals){
        if(root == NULL)
            return;
        inOrder(root->left, vals);
        vals.push_back(root->val);
        inOrder(root->right, vals);
    }
};