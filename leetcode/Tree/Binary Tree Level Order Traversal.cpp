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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root) return ret;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> v;
        while(!q.empty()){
            TreeNode* p = q.front();
            q.pop();
            if(p){
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
                v.push_back(p->val);
            }else if(!q.empty()){
                ret.push_back(v);
                v.clear();
                q.push(NULL);
            }
        }

        ret.push_back(v);

        return ret;
    }
};