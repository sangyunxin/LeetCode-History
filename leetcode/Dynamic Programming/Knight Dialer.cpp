class Solution {
public:
    int knightDialer(int N) {
        long long mod = 1e9 + 7;
        map<int, vector<int>> m = {
            {1, {6, 8}}, {2, {7, 9}}, {3, {4, 8}},
            {4, {3, 9, 0}}, {6, {1, 7, 0}},
            {7, {2, 6}}, {8, {1, 3}}, {9, {2, 4}},
            {0, {4, 6}}
        };
        vector<long long> dp(10, 1);
        long long ret = 0;
        for(int i = 1; i < N; ++i){
            vector<long long> cur(10, 0);
            for(int j = 0; j < 10; ++j){
                for(int p: m[j]){
                    cur[j] += dp[p] % mod;
                }
            }

            dp = cur;
        }

        for(long long num: dp){
            ret += num;
        }

        return ret % mod;
    }
};