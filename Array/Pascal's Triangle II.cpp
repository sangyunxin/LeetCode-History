class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret(rowIndex+1, 1);
        for(int k = 1; k <= rowIndex; ++k)
        {
            for(int j = k-1; j > 0; --j)
            {
                ret[j] = ret[j] + ret[j-1];
            }
        }

        return ret;
    }
};