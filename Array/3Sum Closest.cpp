class Solution {    
public:
    int res;
    void dfs(vector<int>& nums, int target, int sum, int i, int j){
        if(i == 3){
            if(std::abs(sum-target) < std::abs(res-target)){
                res = sum;
            }
            return;
        }
        
        for(int k = j; k < nums.size(); k++){
            dfs(nums, target, sum+nums[k], i+1, k+1);
        }
    }
    
    int threeSumClosest(vector<int>& nums, int target) {
        res = nums[0] + nums[1] + nums[2];
        dfs(nums, target, 0, 0, 0);
        return res;
    }
};