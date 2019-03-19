class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1)
            return n == 0 ? 0: nums[0];

        return max(robber(nums, 0, n-2), robber(nums, 1, n-1));

    }

private:
    int robber(vector<int>& nums, int start, int end){
        int pre = 0, cur = 0;
        for(int i = start; i <= end; ++i){
            int temp = max(pre+nums[i], cur);
            pre = cur;
            cur = temp;
        }

        return cur;
    }
};