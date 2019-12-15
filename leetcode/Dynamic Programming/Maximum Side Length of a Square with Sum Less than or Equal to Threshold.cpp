class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size(), ret = 0;
        if(m == 0 || n == 0) return ret;
        vector<vector<int>> sum(m+1, vector<int>(n+1, 0));

        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + mat[i-1][j-1];
                int l = min(i, j);
                while(l > ret){
                    if(sum[i][j] - sum[i][j-l] - sum[i-l][j] + sum[i-l][j-l] <= threshold){
                        ret = l;
                        break;
                    }
                    l--;
                }
            }
        }

        return ret;
    }
};