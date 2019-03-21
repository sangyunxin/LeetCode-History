class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, 0);
        for(int i = 1; i <= n; i++){
            int ret = i;
            for(int j = 1; j * j <= i; j++)
                ret = min(1 + dp[i-j*j], ret);

            dp[i] = ret;
        }
            //printf("%d: %d\n", i, dp[i]);

        return dp[n];
    }
};