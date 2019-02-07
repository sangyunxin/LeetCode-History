class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>::iterator it;
        while((it = find(nums.begin(), nums.end(), val)) != nums.end())
            nums.erase(it);
        return nums.size();
    }
};