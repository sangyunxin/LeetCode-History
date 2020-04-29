class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int ret = nums[0], n = nums.size();

        deque<int> dp;
        for(int i = 0; i < n; ++i){
            nums[i] += (dp.size()? dp.front(): 0);
            ret = max(nums[i], ret);
            while(dp.size() && dp.back() < nums[i])
                dp.pop_back();
            if(nums[i] > 0)
                dp.push_back(nums[i]);
            if(i >= k && dp.size() && nums[i-k] == dp.front())
                dp.pop_front();
        }

        return ret;
    }
};