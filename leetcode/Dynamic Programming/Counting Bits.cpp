class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1, 0);
        if(num == 0) return dp;

        dp[1] = 1;
        for(int i = 2; i <= num; ++i){
            dp[i] = dp[i/2] + i % 2;
        }

        return dp;
    }
};