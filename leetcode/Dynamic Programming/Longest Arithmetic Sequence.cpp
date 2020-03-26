class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        if(A.size() == 1)
            return 1;
        int ret = 1;
        unordered_map<int, unordered_map<int, int>> dp;
        for(int i = 0; i < A.size(); ++i){
            for(int j = 0; j < i; ++j){
                int diff = A[i] - A[j];
                dp[i][diff] = dp[j][diff] + 1;
                ret = max(dp[i][diff], ret);
            }
        }

        return ret + 1;
    }
};