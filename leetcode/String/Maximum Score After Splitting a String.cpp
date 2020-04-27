class Solution {
public:
    int maxScore(string s) {
        int all = 0, ret = 0, cur = 0;
        for(int i = 0; i < s.size(); ++i){
            all += s[i] - '0';
        }

        for(int i = 0; i < s.size() - 1; ++i){
            cur += s[i] - '0';
            ret = max(ret, i + 1 - 2 * cur + all);
        }

        return ret;

    }
};