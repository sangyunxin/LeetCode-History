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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(!nums.size()) return NULL;
        return helper(nums, 0, nums.size() - 1);
    }

    TreeNode* helper(vector<int>& nums, int start, int end){
        int mid = (start + end) % 2 == 0? (start + end) / 2: (start + end) / 2 + 1;
        // cout << mid << endl;
        TreeNode *cur = new TreeNode(nums[mid]);
        if(start < end){
            if(mid - 1 >= start)
                cur->left = helper(nums, start, mid-1);
            if(mid + 1 <= end)
                cur->right = helper(nums, mid+1, end);
        }
        return cur;
    }
};