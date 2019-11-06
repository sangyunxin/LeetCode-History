class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int start = 0, n = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == 0){
                n++;
                continue;
            }
            nums[i-n] = nums[i];
        }

        for(int i = nums.size() - n; i < nums.size(); ++i)
            nums[i] = 0;
    }
};