class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret;
        if(n == 0) return ret;
        if(n == 1){
            ret.push_back(nums[0]);
            return ret;
        }

        sort(nums.begin(), nums.end());
        vector<int> dp(n, 0);
        vector<int> next(n, 0);
        int reti = 0, retl = 0;

        for(int i = n-1; i >= 0; --i){
            for(int j = i; j < n; ++j){
                if(nums[j] % nums[i] == 0 && dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    next[i] = j;
                }
            }

            if(dp[i] > retl){
                reti = i;
                retl = dp[i];
            }
        }

        for(int i = 0; i < retl; ++i){
            ret.push_back(nums[reti]);
            reti = next[reti];
        }

        return ret;
    }
};