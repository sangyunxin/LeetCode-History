class Solution {
public:
    bool flag = false;
    bool PredictTheWinner(vector<int>& nums) {
        return canWin(nums, 0, nums.size()-1, 0, 0) || flag;
    }

    bool canWin(vector<int>& nums, int start, int end, int sum1, int sum2){
        if(start > end){
            if(sum1 == sum2)
                flag = true;
            return sum1 >= sum2;
        }
        return !canWin(nums, start+1, end, sum2, sum1+nums[start]) || !canWin(nums, start, end-1, sum2, sum1+nums[end]);
    }
};