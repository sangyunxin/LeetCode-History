class Solution {
public:
    bool divisorGame(int N) {
        vector<int> dp(N+1, 0);
        dp[1] = 1;
        return canWin(N, dp);
    }

    bool canWin(int N, vector<int>& dp)
    {
        if(dp[N] != 0)
            return dp[N] == 1? false: true;

        for(int i = 1; i <= N/2; ++i)
            if(N % i == 0 && !canWin(N-i, dp)){
                dp[N] = 2;
                return true;
            }

        dp[N] = 1;

        return false;

    }
};