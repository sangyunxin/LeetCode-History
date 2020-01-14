class Solution {
public:
    vector<vector<int>> g;
    vector<bool> visit;

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1)
            return -1;

        g.resize(n, vector<int>());
        visit.resize(n, false);
        for(auto e: connections){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        int ret = 0;
        for(int i = 0; i < n; ++i)
            ret += dfs(i);
        return ret - 1;
    }

    int dfs(int start){
        if(visit[start])
            return 0;
        visit[start] = true;
        for(int v: g[start])
            dfs(v);
        return 1;
    }
};