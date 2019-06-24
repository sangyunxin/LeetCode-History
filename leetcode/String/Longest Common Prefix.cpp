class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 0)
            return "";
        string s0 = strs[0];
        int len = 0;
        while (len < s0.size())
        {
            bool flag = false;
            for (int j = 1; j < strs.size(); ++j)
            {
                if (s0[len] != strs[j][len])
                {
                    flag = true;
                    break;
                }
            }

            if (flag)
                break;
            len++;
        }

        return s0.substr(0, len);
    }
};