class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        if(mines.size() == N * N) return 0;
        int ret = 1;
        vector<vector<int>> ul(N, vector<int>(N, 1));
        vector<vector<int>> dr(N, vector<int>(N, 1));
        
        for(auto m: mines){
            ul[m[0]][m[1]] = dr[m[0]][m[1]] = 0;
        }
        
        vector<int> up(ul[0]);
        vector<int> down(dr[N-1]);
        
        
        for(int i = 1; i < N; ++i){
            int left = ul[i][0];
            for(int j = 1; j < N; ++j){
                if(ul[i][j] == 0){
                    left = 0;
                    up[j] = 0;
                    continue;
                }
                ul[i][j] = min(++left, ++up[j]);
            }
        }
        
        for(int i = N - 2; i >= 0; --i){
            int right = dr[i][N-1];
            for(int j = N - 2; j >= 0; --j){
                if(dr[i][j] == 0){
                    right = 0;
                    down[j] = 0;
                    continue;
                }
                dr[i][j] = min(++right, ++down[j]);
                int tmp = min(ul[i][j], dr[i][j]);
                //cout << i << "," << j << "," << ul[i][j] << "," << dr[i][j] << endl;
                ret = max(ret, tmp);
            }
        }
        
        return ret;
    }
};