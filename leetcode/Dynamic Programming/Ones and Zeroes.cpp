class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        int zeros, ones;
        for(string s: strs){
            zeros = ones = 0;
            for(char c: s){
                if(c == '0')
                    zeros++;
                else if(c == '1')
                    ones++;
            }

            for(int i = m; i >= zeros; --i)
                for(int j = n; j >= ones; --j)
                    dp[i][j] = max(dp[i][j], dp[i-zeros][j-ones]+1);
        }

        return dp[m][n];

    }
};