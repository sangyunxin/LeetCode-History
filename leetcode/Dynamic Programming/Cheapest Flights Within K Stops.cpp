class Solution {
public:
    int ret = INT_MAX;
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>> g(n, vector<int>(n, -1));
        for(auto e: flights){
            g[e[0]][e[1]] = e[2];
        }
        
        helper(n, g, src, dst, K+1, 0);
        return ret == INT_MAX? -1: ret;
    }
    
    void helper(int n, vector<vector<int>>& g, int src, int dst, int K, int cost){
        if(cost > ret)
            return;
        
        if(src == dst){
            ret = min(ret, cost);
            return;
        }
            
        if(K == 0) return;
        
        for(int i = 0; i < n; ++i){
            if(g[src][i] >= 0){
                helper(n, g, i, dst, K-1, cost+g[src][i]);
            }
        }
    }
};