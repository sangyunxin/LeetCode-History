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
    vector<TreeNode*> BuildTree(int start, int end){
        vector<TreeNode*> res;
        if(start > end){
            res.push_back(NULL);
            return res;
        }

        if(start == end){
            res.push_back(new TreeNode(start));
            return res;
        }

        for(int i = start; i <= end; i++){
            vector<TreeNode*> left = BuildTree(start, i-1);
            vector<TreeNode*> right = BuildTree(i+1, end);

            for(TreeNode* lnode: left){
                for(TreeNode* rnode: right){
                    TreeNode *root = new TreeNode(i);
                    root -> left = lnode;
                    root -> right = rnode;
                    res.push_back(root);
                }
            }
        }

        return res;
    }

    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if(n != 0)
            res = BuildTree(1, n);
        return res;
    }
};