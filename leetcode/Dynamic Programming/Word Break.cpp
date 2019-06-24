class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        for(int i = 0; i < dp.size(); ++i)
            for(int j = i-1; j >= 0; --j)
                if(dp[j] && wordSet.count(s.substr(j, i-j))){
                    dp[i] = true;
                    break;
                }
        return dp.back();
    }
};