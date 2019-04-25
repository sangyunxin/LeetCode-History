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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> vals1, vals2;
        preOrder(root1, vals1);
        preOrder(root2, vals2);
        if(vals1.size() != vals2.size())
            return false;
        for(int i = 0; i < vals1.size(); ++i)
            if(vals1[i] != vals2[i])
                return false;
        return true;
    }

    void preOrder(TreeNode* root, vector<int>& vals){
        if(root->left == NULL && root->right == NULL){
            vals.push_back(root->val);
            return;
        }
        if(root->left != NULL)
            preOrder(root->left, vals);
        if(root->right != NULL)
            preOrder(root->right, vals);
    }
};