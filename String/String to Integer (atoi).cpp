class Solution
{
public:
    int myAtoi(string str)
    {
        int start = 0, ret = 0, sign = 1;
        while (start < str.size() && str[start] == ' ')
        {
            start++;
        }

        if (start >= str.size() || !(isdigit(str[start]) || str[start] == '-' || str[start] == '+'))
        {
            return 0;
        }

        if (str[start] == '-')
        {
            sign = -1;
            start++;
        }
        else if (str[start] == '+')
        {
            start++;
        }

        while (start < str.size() && isdigit(str[start]))
        {
            if (ret == 214748364 && str[start] > '7' || ret > 214748364)
            {
                if (sign == 1)
                    return 2147483647;
                else
                    return -2147483648;
            }
            ret = ret * 10 + (str[start] - '0');
            start++;
        }

        return sign * ret;
    }
};