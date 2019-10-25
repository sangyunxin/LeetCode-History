class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int n = A.size();
        vector<double> sums(n+1, 0);
        vector<vector<double>> dp(n+1, vector<double>(K+1, 0));
        
        for(int i = 1; i <= n; ++i)
            sums[i] = sums[i-1] + A[i-1];
        
        for(int i = 1; i <= n; ++i)
            dp[i][1] = sums[i] / i;
        
        for(int k = 2; k <= K; ++k){
            for(int i = 1; i <= n; ++i){
                for(int j = 0; j < i; ++j){
                    dp[i][k] = max(dp[i][k], (sums[i] - sums[j]) / (i - j) + dp[j][k-1]);
                }
            }
        }
                                   
        return dp[n][K];
        
    }
};