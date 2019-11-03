class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), ret = 0;
        vector<int> pos;

        pos.push_back(-1);
        for(int i = 0; i < n; ++i){
            if(nums[i] % 2 == 1)
                pos.push_back(i);
        }
        pos.push_back(n);

        if(pos.size() < k + 2) return 0;
        for(int i = 1; i < pos.size() - k; ++i){
            int left = pos[i] - pos[i-1], right = pos[i + k] - pos[i + k - 1];
            ret += left * right;
        }

        return ret;
    }
};