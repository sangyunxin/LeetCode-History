class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int n = A.size(), ret = 0;
        map<int, int> v2i;
        for(int i = 0; i < n; ++i)
            v2i[A[i]] = i;
        vector<vector<int>> dp(n, vector<int>(n, 2));

        for(int i = 1; i < n - 1; ++i){
            for(int j = i + 1; j < n; ++j){
                if(A[j] - A[i] >= A[i])
                    break;
                if(v2i.count(A[j] - A[i]) > 0){
                    dp[i][j] = dp[v2i[A[j] - A[i]]][i] + 1;
                    ret = max(dp[i][j], ret);
                }
            }
        }

        return ret;
    }
};