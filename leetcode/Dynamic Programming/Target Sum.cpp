class Solution {
public:
    int count;

    int findTargetSumWays(vector<int>& nums, int S) {
        count  = 0;
        bt(nums, S, 0, 0);
        return count;
    }

    void bt(vector<int>& nums, int S, int i, int sum){
        if(i == nums.size()){
            if(sum == S)
                count++;
            return;
        }

        bt(nums, S, i+1, sum+nums[i]);
        bt(nums, S, i+1, sum+nums[i]*(-1));
    }
};