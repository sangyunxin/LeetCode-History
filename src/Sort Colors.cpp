class Solution {
public:
    void swap(vector<int>& nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    
    void sortColors(vector<int>& nums) {
        int start = 0, mid = 0, end = nums.size() - 1;
        while(mid <= end){
            if(nums[mid] == 0)
                swap(nums, mid++, start++);
            else if(nums[mid] == 2)
                //这里不能做mid++，因为如果换过来的是0要再判断一次
                swap(nums, mid, end--);
            else
                mid++;
        }
    }
};