class Solution {
public:
    bool helper(vector<vector<int>>& s, int sum){
        for(int i = 0; i < 3; ++i){
            if(s[i][0] + s[i][1] + s[i][2] == sum || s[0][i] + s[1][i] + s[2][i] == sum)
                return true;
        }

        if(s[0][0] + s[1][1] + s[2][2] == sum || s[0][2] + s[1][1] + s[2][0] == sum)
            return true;
        return false;
    }

    string tictactoe(vector<vector<int>>& moves) {
        int n = moves.size();
        vector<vector<int>> s(3, vector<int>(3, 0));
        for(int i = 0; i < n; ++i){
            if(i % 2 == 0)
                s[moves[i][0]][moves[i][1]] = 1;
            else
                s[moves[i][0]][moves[i][1]] = -1;
        }

        if(n % 2 != 0 && helper(s, 3))
            return "A";
        else if(n % 2 == 0 && helper(s, -3))
            return "B";
        else if(n < 9)
            return "Pending";
        else
            return "Draw";

    }
};