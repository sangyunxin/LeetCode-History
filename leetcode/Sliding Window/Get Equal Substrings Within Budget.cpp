class Solution {
public:
    int ret = INT_MIN;
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size(), left = -1, right = 0, cost = 0, ret = 0;
        vector<int> diff(n, 0);
        for(int i = 0; i < n; ++i){
            diff[i] = s[i] >= t[i]? s[i] - t[i]: t[i] - s[i];
        }
        
        for(; right < n; ++right){
            cost += diff[right];
            while(cost > maxCost && left < right){
                cost -= diff[++left];
            }
            ret = max(ret, right - left);
        }
        
        return ret;
    }
};