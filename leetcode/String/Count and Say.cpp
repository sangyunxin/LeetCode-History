class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";
        string prev = "11", cur;
        for (int i = 3; i <= n; ++i)
        {
            cur = "";
            char c = prev[0];
            //cout << c << endl;
            int count = 1;
            for (int j = 1; j < prev.size(); ++j)
            {
                if (prev[j] == c)
                    count++;
                else
                {
                    cur += '0' + count;
                    cur += c;
                    count = 1;
                    c = prev[j];
                }
            }
            cur += '0' + count;
            cur += c;
            prev = cur;
        }

        return prev;
    }
};