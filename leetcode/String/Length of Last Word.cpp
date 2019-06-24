class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int ret = 0;
        s.erase(s.find_last_not_of(" ") + 1);
        for (int i = s.size() - 1; i >= 0; --i)
        {
            if (s[i] == ' ')
                break;
            ret++;
        }

        return ret;
    }
};