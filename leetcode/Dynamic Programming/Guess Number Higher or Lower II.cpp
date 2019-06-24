class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        return dps(1, n, dp);
    }

    int dps(int start, int end, vector<vector<int>>& dp){
        if(start >= end) return 0;
        if(dp[start][end] > 0) return dp[start][end];

        int ret= INT_MAX;
        for(int i = start; i <= end; i++)
            ret = min(max(dps(start, i-1, dp), dps(i+1, end, dp)) + i, ret);

        dp[start][end] = ret;
        return ret;
    }
};