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
    TreeNode* helper(vector<int>& preorder, int pi, int pj, vector<int>& inorder, int ii, int ij){
        // tree        8 4 5 3 7 3
        // preorder    8 [4 3 3 7] [5]
        // inorder     [3 3 4 7] 8 [5]

        if(pi >= pj || ii >= ij)
            return NULL;

        int mid = preorder[pi];
        TreeNode* root = new TreeNode(mid);

        auto iter = find(inorder.begin()+ii, inorder.begin()+ij, mid);
        int dis = iter - inorder.begin() - ii;
        root -> left = helper(preorder, pi+1, pi+dis+1, inorder, ii, ii+dis);
        root -> right = helper(preorder, pi+dis+1, pj, inorder, ii+dis+1, ij);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = helper(preorder, 0, preorder.size(), inorder, 0, inorder.size());
        return root;
    }
};