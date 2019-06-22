class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> ret;
        if (nums.size() == 0)
            return ret;
        string cur = to_string(nums[0]);
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] != nums[i - 1] + 1)
            {
                if (cur != to_string(nums[i - 1]))
                {
                    cur += "->" + to_string(nums[i - 1]);
                }

                ret.push_back(cur);
                cur = to_string(nums[i]);
            }
        }

        if (cur != "")
        {
            if (cur != to_string(nums.back()))
                cur += "->" + to_string(nums.back());
            ret.push_back(cur);
        }

        return ret;
    }
};