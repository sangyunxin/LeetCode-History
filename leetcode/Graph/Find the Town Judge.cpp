class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> d(N+1, 0);
        for(int i = 0; i < trust.size(); ++i){
            d[trust[i][0]]--;
            d[trust[i][1]]++;
        }

        for(int i = 1; i <= N; ++i)
            if(d[i] == N - 1)
                return i;
        return -1;
    }
};