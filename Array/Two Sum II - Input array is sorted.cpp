class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ret;

        for(int i = 0; i < numbers.size(); ++i)
        {
            if(i > 0 && numbers[i] == numbers[i-1])
                continue;
            for(int j = i+1; j < numbers.size(); ++j)
            {
                if(numbers[i]+numbers[j] > target)
                    break;
                if(numbers[i]+numbers[j] == target)
                {
                    ret.push_back(i+1);
                    ret.push_back(j+1);
                    return ret;
                }
            }
        }

        return ret;
    }
};