class Solution {
public:
    int min3(int a, int b, int c){
        return a < b ? (a < c ? a : c) : (b < c ? b : c);
    }

    int minFallingPathSum(vector<vector<int>>& A) {
        int ret = INT_MAX, n = A.size();
        if(n == 1) return A[0][0];
        vector<int> dp(n, 0);
        for(int i = 0; i < n; ++i){
            vector<int> cur;
            for(int j = 0; j < n; ++j){
                if(j == 0)
                    cur.push_back(min(dp[j], dp[j+1]) + A[i][j]);
                else if(j == n - 1)
                    cur.push_back(min(dp[j-1], dp[j]) + A[i][j]);
                else
                    cur.push_back(min3(dp[j-1], dp[j], dp[j+1]) + A[i][j]);
            }
            dp = cur;
        }

        for(int s: dp)
            ret = min(ret, s);
        return ret;
    }
};