class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b){
            if(a[0] == b[0])
                return a[1] <= b[1];
            return a[0] < b[0];
        });
        vector<int> dp(pairs.size(), 1);
        int ret = 0;
        for(int i = 0; i < pairs.size(); ++i){
            for(int j = 0; j < i; ++j){
                if(pairs[i][0] > pairs[j][1])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            ret = max(dp[i], ret);
        }
        
        return ret;
    }
};