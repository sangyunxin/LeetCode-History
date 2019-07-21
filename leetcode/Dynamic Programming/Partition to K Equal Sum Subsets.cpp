class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % k != 0) return false;
        vector<bool> vis(nums.size(), false);
        return helper(nums, vis, k, sum / k, 0, 0);
    }
    
    bool helper(vector<int>& nums, vector<bool>& vis, int k, int target, int cur, int start){
        if(k == 1) return true;
        if(cur > target) return false;
        if(cur == target) return helper(nums, vis, k-1, target, 0, 0);
        for(int i = start; i < nums.size(); ++i){
            if(vis[i])
                continue;
            vis[i] = true;
            if(helper(nums, vis, k, target, cur+nums[i], i+1)) return true;
            vis[i] = false;
        }
        
        return false;
    }
};