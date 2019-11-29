class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        if(N == 1) return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> dp = {1, 2, 3, 4, 5, 6, 7, 8, 9};

        for(int i = 2; i <= N; ++i){
            vector<int> cur;
            for(int pre: dp){
                int p = pre % 10;
                if(K == 0){
                    cur.push_back(pre * 10 + p);
                    continue;
                }
                if(p - K >= 0)
                    cur.push_back(pre * 10 + p - K);
                if(p + K <= 9)
                    cur.push_back(pre * 10 + p + K);
            }
            dp = cur;
        }

        return dp;
    }
};