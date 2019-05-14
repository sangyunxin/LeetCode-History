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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int istart, int iend, int pstart, int pend){
        int len = iend-istart;
        if(len == 0) return new TreeNode(inorder[istart]);
        if(len < 0) return NULL;

        for(int i = istart; i <= iend; ++i){
            if(inorder[i] == postorder[pend]){
                len = i - istart;
                break;
            }
        }

        TreeNode* root = new TreeNode(inorder[istart+len]);
        root->left = build(inorder, postorder, istart, istart+len-1, pstart, pstart+len-1);
        root->right = build(inorder, postorder, istart+len+1, iend, pstart+len, pend-1);
        return root;
    }
};