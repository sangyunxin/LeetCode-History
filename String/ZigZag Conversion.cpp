class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (s.size() <= 2 || numRows <= 1)
            return s;
        string rs = "";
        for (int row = 0; row < numRows; ++row)
        {
            int index = row, d = 1;
            while (index < s.size())
            {
                rs += s[index];
                if (row == 0 || row == numRows - 1 || d)
                    index += 2 * (numRows - (row % (numRows - 1)) - 1);
                else
                    index += 2 * (row % (numRows - 1));
                d ^= 1;
            }
        }

        return rs;
    }
};