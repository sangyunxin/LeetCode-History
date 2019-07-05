class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<int>> dirs = {
            {-2, -1}, {-1, -2}, {1, 2}, {2, 1},
            {2, -1}, {1, -2}, {-1, 2}, {-2, 1}
        };
        
        vector<vector<double>> dp(N, vector<double>(N, 1));
        for(int k = 1; k <= K; ++k){
            vector<vector<double>> cur(N, vector<double>(N, 0));
            for(int x = 0; x < N; ++x){
                for(int y = 0; y < N; ++y){
                    for(auto d: dirs){
                        if(x + d[0] >= 0 && x + d[0] < N && y + d[1] >= 0 && y + d[1] < N)
                            cur[x][y] += dp[x + d[0]][y + d[1]];
                    }
                }                           
            }
            dp = cur;
        }
        
        return dp[r][c] / pow(8, K);
    }
};