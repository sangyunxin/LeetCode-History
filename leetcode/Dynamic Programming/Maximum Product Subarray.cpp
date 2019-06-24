class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        vector<int> ne(n, 1);
        dp[0] = nums[0];
        int ret = nums[0];
        for(int i = 1; i < n; i++){
            if(ne[i-1] < 0 && nums[i] < 0)
                dp[i] = max(ne[i-1]*nums[i], nums[i]);
            else
                dp[i] = max(dp[i-1]*nums[i], nums[i]);

            ret = max(dp[i], ret);
            if(nums[i] * ne[i-1] < 0 || nums[i] < 0){
                ne[i] = min(nums[i] * dp[i-1], nums[i] * ne[i-1]);
                ne[i] = min(ne[i], nums[i]);
            }


        }

        return ret;
    }
};