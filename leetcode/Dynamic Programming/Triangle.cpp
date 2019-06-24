class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n, 0);
        dp[0] = triangle[0][0];
        for(int i = 1; i < n; i++){
            for(int j = i; j >= 0; j--){
                if(j == 0)
                    dp[j] += triangle[i][j];
                else if(j == i)
                    dp[j] = dp[j-1] + triangle[i][j];
                else
                    dp[j] = min(dp[j], dp[j-1]) + triangle[i][j];
                //printf("%d, %d\n", j, dp[j]);
            }

        }

        vector<int>::iterator min = min_element(dp.begin(), dp.end());

        return *min;
    }
};