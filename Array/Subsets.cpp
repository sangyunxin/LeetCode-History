class Solution {
public:
    vector<vector<int>> res;
    
    void dfs(vector<int>& nums, vector<int>& cur, int start){
        if(start >= nums.size()){
            res.push_back(cur);
            return;
        }
        
        for(int i = start; i < nums.size(); i++){
            if(i > start && nums[i] == nums[i-1])
                continue;
            
            cur.push_back(nums[i]);
            dfs(nums, cur, i+1);
            cur.pop_back();
        }
        
        dfs(nums, cur, nums.size());
            
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> cur;
        dfs(nums, cur, 0);
        
        return res;
    }
};