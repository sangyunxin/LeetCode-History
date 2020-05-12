class Solution {
public:
    int dps(int m, int n, int r, int c, int rest, vector<vector<vector<int>>>& dp, vector<vector<int>>& preSum){
        if(preSum[r][c] == 0) return 0;
        if(rest == 0) return 1;
        if(dp[r][c][rest] != -1) return dp[r][c][rest];

        int ans = 0;
        for(int i = r + 1; i < m; ++i){
            if(preSum[r][c] - preSum[i][c] > 0){
                ans = (ans + dps(m, n, i, c, rest-1, dp, preSum)) % 1000000007;
            }
        }

        for(int j = c + 1; j < n; ++j){
            if(preSum[r][c] - preSum[r][j] > 0)
                ans = (ans + dps(m, n, r, j, rest-1, dp, preSum)) % 1000000007;
        }

        return dp[r][c][rest] = ans;
    }

    int ways(vector<string>& pizza, int k) {
        int m = pizza.size(), n = pizza[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, -1)));
        vector<vector<int>> preSum(m+1, vector<int>(n+1, 0));
        for(int r = m-1; r >= 0; --r)
            for(int c = n-1; c >= 0; --c)
                preSum[r][c] = preSum[r][c+1] + preSum[r+1][c] - preSum[r+1][c+1] + (pizza[r][c] == 'A');

        return dps(m, n, 0, 0, k-1, dp, preSum);
    }
};