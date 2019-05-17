class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        int t = nums.size() / 2;
        for(int num: nums)
        {
            if(m.find(num) == m.end())
                m[num] = 1;
            else
                m[num]++;
        }

        for(auto it = m.begin(); it != m.end(); ++it){
            if(it->second > t)
                return it->first;
        }

        return -1;
    }
};