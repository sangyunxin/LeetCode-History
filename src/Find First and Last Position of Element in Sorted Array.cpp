class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        vector<int> res(2, -1);
        
        if(nums.size() == 0) return res;
        
        while(start < end){
            int mid = (start + end) / 2;
            if(nums[mid] >= target)
                end = mid;
            else
                start = mid + 1;
        }
        
        if(nums[start] != target) return res;
        else res[0] = start;
        
        end = nums.size() - 1;
        while(start < end){
            int mid = (start + end) / 2 + 1;
            if(nums[mid] <= target)
                start = mid;
            else
                end = mid - 1;
        }
        
        res[1] = end;
        return res;
    }
};