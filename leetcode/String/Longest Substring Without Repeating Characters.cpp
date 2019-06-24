class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int len = 0, left = 0, right = 0;
        unordered_map<char, int> m;
        while (right < s.size())
        {
            char c = s[right];
            if (m.count(c) && m[c] >= left)
            {
                len = max(right - left, len);

                left = m[c] + 1;
            }
            m[c] = right;
            right++;
        }

        return max(right - left, len);
    }
};