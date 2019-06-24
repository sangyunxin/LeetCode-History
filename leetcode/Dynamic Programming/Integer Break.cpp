class Solution {
public:
    int integerBreak(int n) {
        if(n == 1)
            return 1;
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        for(int i = 2; i <= n; ++i){
            for(int j = 1; j <= i/2; ++j)
                dp[i] = max(max(dp[i-j], i-j) * max(dp[j], j), dp[i]);
        }

        return dp.back();
    }
};