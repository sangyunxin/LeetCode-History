class Solution {
public:
    vector<int> dir_x = {1, -1, 0, 0};
    vector<int> dir_y = {0, 0, 1, -1};
    bool flag = false;
    
    void search(vector<vector<char>>& board, vector<vector<int>>& vis, string word, int x, int y, int cindex, int m, int n){
        if(cindex == word.size()){
            flag = true;
            return;
        }
        
        for(int i = 0; i < 4; i++){
            int next_x = x + dir_x[i];
            int next_y = y + dir_y[i];
            
            if(next_x < 0 || next_x >= m || next_y < 0 || next_y >= n || vis[next_x][next_y] == 1 || flag)
                continue;
            
            if(board[next_x][next_y] == word[cindex]){
                vis[next_x][next_y] = 1;
                search(board, vis, word, next_x, next_y, cindex+1, m, n);
                vis[next_x][next_y] = 0;
            }
                
        }
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0]){
                    vector<vector<int>> vis(m, vector<int>(n, 0));
                    vis[i][j] = 1;
                    search(board, vis, word, i, j, 1, m, n);
                    if(flag)
                        return true;
                }
            }
        }
        
        return false;
    }
};