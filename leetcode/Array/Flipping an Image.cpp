class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        vector<vector<int>> ret(m, vector<int>(n, 1));
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                ret[i][j] ^= A[i][n-j-1];
            }
        }

        return ret;
    }
};