class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int skip = 0, take = 0, skipi = 0, takei = 0;
        vector<int> sums(10001, 0);
        for(int num: nums){
            sums[num] += num;
        }
        
        for(int i = 0; i < 10001; ++i){
            takei = skipi + sums[i];
            skipi = max(skip, take);
            take = takei; skip = skipi;
        }
        
        return max(take, skip);
    }
};