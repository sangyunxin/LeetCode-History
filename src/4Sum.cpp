class Solution {
public:
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        if(n < 4) return res;
        for(int first = 0; first < n - 2; first++){
            if(nums[first]+nums[first+1]+nums[first+2]+nums[first+3] > target)
                break;
            if(nums[first]+nums[n-1]+nums[n-2]+nums[n-3] < target)
                continue;
            if(first > 0 && nums[first] == nums[first - 1])
                continue;
            for(int second = first + 1; second < n - 1; second++){
                if(nums[first]+nums[second]+nums[second+1]+nums[second+2] > target)
                    break;
                if(nums[first]+nums[second]+nums[n-1]+nums[n-2] < target)
                    continue;
                if(second > first + 1 && nums[second] == nums[second-1])
                    continue;
                int third = second + 1;
                int fourth = n - 1;
                while(third < fourth){
                    int cur = nums[first] + nums[second] + nums[third] + nums[fourth];
                    if(cur > target)
                        fourth--;
                    else if(cur < target)
                        third++;
                    else{
                        res.push_back(vector<int>{nums[first], nums[second], nums[third], nums[fourth]});
                        do{
                            third++;
                        }while(third < fourth && nums[third] == nums[third-1]);
                        do{
                            fourth--;
                        }while(fourth > third && nums[fourth] == nums[fourth+1]);
                    }
                }
            }    
        }
        return res;
    }
};