class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ret;
        int n = nums.size(), max_key = 0;
        unordered_map<int, vector<int>> m;
        for(int i = 0; i < nums.size(); ++i){
            for(int j = 0; j < nums[i].size(); ++j){
                m[i+j].push_back(nums[i][j]);
                max_key = max(max_key, i+j);
            }
        }

        for(int i = 0; i <= max_key; ++i){
            for(auto x = m[i].rbegin(); x != m[i].rend(); ++x){
                ret.push_back(*x);
            }
        }

        return ret;
    }
};