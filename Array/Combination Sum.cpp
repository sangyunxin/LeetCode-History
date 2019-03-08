class Solution {
public:
    vector<vector<int>> res;
    
    void dfs(vector<int>& candidates, int target, vector<int>& cur, int sum, int start){
        if(sum == target){
            res.push_back(cur);
            return;
        }
        if(sum > target)
            return;
        
        for(int i = start; i < candidates.size(); i++){
            cur.push_back(candidates[i]);
            dfs(candidates, target, cur, sum+candidates[i], i);
            cur.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur;
        dfs(candidates, target, cur, 0, 0);
        return res;
    }
};