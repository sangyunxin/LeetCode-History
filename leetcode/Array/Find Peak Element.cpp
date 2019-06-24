class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while(high - low > 1)
        {
            int mid = (low + high) / 2;
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
                return mid;
            else if(nums[mid] > nums[mid+1])
                high = mid - 1;
            else
                low = mid + 1;
        }

        return nums[low] > nums[high]? low: high;
    }
};