class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int n = A.size(), ret = 1;
        vector<vector<int>> dp(2, vector<int>(n, 1));
        for(int i = 1; i < n; ++i){
            if(A[i] > A[i-1]){
                if(i % 2 == 0)
                    dp[0][i] = dp[0][i-1] + 1;
                else
                    dp[1][i] = dp[1][i-1] + 1;
            }else if(A[i] < A[i-1]){
                if(i % 2 == 0)
                    dp[1][i] = dp[1][i-1] + 1;
                else
                    dp[0][i] = dp[0][i-1] + 1;
            }
        }

        for(int i = 0; i < 2; ++i){
            for(int num: dp[i]){
                ret = max(ret, num);
            }
        }

        return ret;
    }
};