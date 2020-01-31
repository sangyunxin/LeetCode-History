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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root) return ret;

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> cur;

        while(!q.empty())
        {
            TreeNode* p = q.front();
            q.pop();
            if(p)
            {
                cur.push_back(p->val);
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
            else if(!q.empty())
            {
                q.push(NULL);
                ret.insert(ret.begin(), cur);
                cur.clear();
            }
        }

        ret.insert(ret.begin(), cur);

        return ret;
    }
};