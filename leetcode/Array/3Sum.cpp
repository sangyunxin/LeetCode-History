class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        if(n < 3 || nums[0] + nums[1] + nums[2] > 0 || nums[n-1] + nums[n-2] + nums[n-3] < 0) 
            return res;
        
        for(int first = 0; first < n; first++){
            if(first > 0 && nums[first] == nums[first-1])
                continue;
            
            int second = first + 1;
            int third = n - 1;
            while(second < third){
                if(second < third && nums[first] + nums[second] + nums[third] == 0){
                    res.push_back(vector<int>{nums[first], nums[second], nums[third]});
                    do{
                        second++;
                    }while(second < third && nums[second] == nums[second-1]);
                    
                    do{
                        third--;
                    }while(second < third && nums[third] == nums[third+1]);
                } 

                //应该使用nums[first] + nums[second] + nums[third]计算当前和，因为third和second一直在变
                while(nums[first] + nums[second] + nums[third] > 0 && second < third)
                    third--;
                while(nums[first] + nums[second] + nums[third] < 0 && second < third)
                    second++;
                   
            }
        }
        
        return res;
    }
};