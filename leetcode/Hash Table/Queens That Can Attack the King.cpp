class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        map<int, vector<int>> m;
        vector<int> dis(8, INT_MAX);
        for(auto q: queens){
            if(q[0] == king[0]){
                if(q[1] - king[1] > 0 && q[1] - king[1] < dis[2]){
                    m[2] = q;
                    dis[2] = q[1] - king[1];
                }
                else if(q[1] - king[1] < 0 && king[1] - q[1] < dis[6]){
                    m[6] = q;
                    dis[6] = king[1] - q[1];
                }
            }else if(q[1] == king[1]){
                if(q[0] - king[0] > 0 && q[0] - king[0] < dis[4]){
                    m[4] = q;
                    dis[4] = q[0] - king[0];
                }
                else if(q[0] - king[0] < 0 && king[0] - q[0] < dis[0]){
                    m[0] = q;
                    dis[0] = king[0] - q[0];
                }
            }else if(q[0] - king[0] == q[1] - king[1]){
                if(q[0] - king[0] > 0 && q[0] - king[0] < dis[3]){
                    m[3] = q;
                    dis[3] = q[0] - king[0];
                }else if(q[0] - king[0] < 0 && king[0] - q[0] < dis[7]){
                    m[7] = q;
                    dis[7] = king[0] - q[0];
                }
            }else if(q[0] - king[0] == king[1] - q[1]){
                if(q[0] - king[0] > 0 && q[0] - king[0] < dis[5]){
                    m[5] = q;
                    dis[5] = q[0] - king[0];
                }else if(q[0] - king[0] < 0 && king[0] - q[0] < dis[1]){
                    m[1] = q;
                    dis[1] = king[0] - q[0];
                }
            }
        }
        
        vector<vector<int>> ret;
        for(int i = 0; i < 8; ++i){
            if(dis[i] < INT_MAX)
                ret.push_back(m[i]);
        }
        
        return ret;
    }
};