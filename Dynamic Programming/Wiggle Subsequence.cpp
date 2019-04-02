class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();

        vector<int> up(n, 1);
        vector<int> down(n, 1);

        for(int i = 1; i < n; ++i){
            for(int j = 0; j < i; ++j){
                if(nums[i] > nums[j])
                    up[i] = max(down[j]+1, up[i]);
                else if(nums[i] < nums[j])
                    down[i] = max(up[j]+1, down[i]);
            }
        }

        return max(up.back(), down.back());
    }
};