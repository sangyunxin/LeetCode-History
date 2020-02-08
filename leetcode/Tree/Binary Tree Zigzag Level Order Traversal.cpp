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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root) return ret;
        queue<TreeNode*> q;
        vector<int> cur;
        q.push(root);
        q.push(NULL);
        int l = 0;
        while(!q.empty()){
            TreeNode* p = q.front();
            q.pop();
            if(p){
                cur.push_back(p->val);
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }else if(!q.empty()){
                if(l % 2) reverse(cur.begin(), cur.end());
                ret.push_back(cur);
                cur.clear();
                l++;
                q.push(NULL);
            }
        }

        if(l % 2) reverse(cur.begin(), cur.end());
        ret.push_back(cur);
        return ret;
    }
};