class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        int len = 0, left = -1, right = 0;
        unordered_map<char, int> m;
        while(right < s.size()){
            char c = s[right];
            if(m.count(c) && m[c] >= left)
                left = m[c];
            len = max(right - left, len);
            m[c] = right++;
        }

        return len;
    }
};