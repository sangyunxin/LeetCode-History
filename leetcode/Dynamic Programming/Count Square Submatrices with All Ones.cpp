class Solution {
public:
    int min3(int a, int b, int c){
        return a < b ? (a < c ? a : c) : (b < c ? b : c);
    }

    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), ret = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i = 0; i < m; ++i){
            dp[i][0] = matrix[i][0];
        }

        for(int j = 0; j < n; ++j){
            dp[0][j] = matrix[0][j];
        }

        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                if(matrix[i][j] == 1)
                    dp[i][j] = min3(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1;
            }
        }

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j)
                ret += dp[i][j];
            //     cout << dp[i][j] << " ";
            // cout << endl;
        }

        return ret;
    }
};