class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1, mid = -1;
        while(start <= end){
            mid = (start + end) / 2;
            if(nums[mid] == target)
                return true;
            else if(nums[mid] > nums[start]){
                if(nums[mid] > target && target >= nums[start])
                    end = mid - 1;
                else
                    start = mid + 1;
                    
            }else if(nums[mid] < nums[start]){
                if(nums[mid] < target && target <= nums[end])
                    start = mid + 1;
                else
                    end =  mid - 1;
            }else{
                start++;
            }
        }
        
        //printf("%d, %d, %d", start, end, mid);
        
        return false;
    }
};