class Solution {
public:
    void swap(vector<int>& nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 1;
        if(n < 2)
            return;
        
        while(i > 0 && nums[i-1] >= nums[i]){
            i--;
        }
        
        if(i == 0)
            sort(nums.begin(), nums.end());
        else{
            i--;
            int j = n - 1;
            while(j > i){
                if(nums[j] > nums[i])
                    break;
                j--;
            }
            swap(nums, i, j);
            sort(nums.begin()+i+1, nums.end());
        }
    }
};