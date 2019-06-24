class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        vector<vector<int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int rx, ry, ret = 0;
        bool flag = false;

        for(rx = 0; rx < 8; ++rx)
        {
            for(ry = 0; ry < 8; ++ry)
            {
                if(board[rx][ry] == 'R'){
                    flag = true;
                    break;
                }
            }

            if(flag) break;
        }

        for(vector<int>& cd: d){
            int x = rx, y = ry;
            while(x+cd[0] >= 0 && x+cd[0] < 8 && y+cd[1] >= 0 && y+cd[1] < 8){
                x = x + cd[0];
                y = y + cd[1];
                if(board[x][y] == 'B')
                    break;
                if(board[x][y] == 'p'){
                    ret++;
                    break;
                }

            }
        }

        return ret;

    }
};