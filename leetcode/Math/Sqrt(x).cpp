class Solution
{
public:
    int mySqrt(int x)
    {
        if (x <= 1)
            return x;
        if (x >= 2147395600)
            return 46340;
        int left = 0, right = x;
        long mid = 0;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (mid * mid == x)
                return mid;
            else if (mid * mid > x)
                right = mid - 1;
            else
                left = mid + 1;
        }

        return left - 1;
    }
};