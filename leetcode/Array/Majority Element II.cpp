class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int a, b, cnt1 = 0, cnt2 = 0, n = nums.size() / 3;
        for (int num : nums)
        {
            if (a == num)
                cnt1++;
            else if (b == num)
                cnt2++;
            else if (cnt1 == 0)
            {
                a = num;
                cnt1 = 1;
            }
            else if (cnt2 == 0)
            {
                b = num;
                cnt2 = 1;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = cnt2 = 0;
        for (int num : nums)
        {
            if (a == num)
                cnt1++;
            else if (b == num)
                cnt2++;
        }

        vector<int> ret;
        if (cnt1 > n)
            ret.push_back(a);
        if (cnt2 > n)
            ret.push_back(b);
        return ret;
    }
};