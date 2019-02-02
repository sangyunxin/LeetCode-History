class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0, reach = 0, n = nums.size();
        for(; i <= reach && i < n; i++){
            reach = max(reach, nums[i] + i);
        }
        return i == n;
    }
};