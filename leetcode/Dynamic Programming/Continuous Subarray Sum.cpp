class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        int sum = 0, pre = 0;
        unordered_set<int> s;
        for (int num : nums)
        {
            sum += num;
            int t = (k == 0) ? sum : sum % k;
            if (s.count(t))
                return true;
            s.insert(pre);
            pre = t;
        }
        return false;
    }
};