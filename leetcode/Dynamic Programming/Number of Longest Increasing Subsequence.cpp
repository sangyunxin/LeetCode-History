class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), r = 0, l = 1;
        vector<int> len(n, 1);
        vector<int> cnt(n, 1);
        for(int i = 0; i < n; ++i){
            for(int j = i - 1; j >= 0; --j){
                if(nums[i] > nums[j]){
                    if(len[j] + 1 == len[i]){
                        cnt[i] += cnt[j];
                    }else if(len[j] + 1 > len[i]){
                        len[i] = len[j] + 1;
                        cnt[i] = cnt[j];
                    }
                }
            }
            if(len[i] == l){
                r += cnt[i];
            }else if(len[i] > l){
                l = len[i];
                r = cnt[i];
            }
        }
        return l == 1? n: r;
    }
};