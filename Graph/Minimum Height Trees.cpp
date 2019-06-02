class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<int> ret;
        vector<unordered_set<int>> graph(n);
        queue<int> q;
        for(auto e: edges){
            graph[e[0]].insert(e[1]);
            graph[e[1]].insert(e[0]);
        }

        for(int i = 0; i < n; ++i)
            if(graph[i].size() == 1)
                q.push(i);

        while(n > 2){
            int len = q.size();
            n -= len;
            for(int i = 0; i < len; ++i){
                int c = q.front(); q.pop();
                for(auto a: graph[c]){
                    graph[a].erase(c);
                    if(graph[a].size() == 1)
                        q.push(a);
                }
            }
        }

        while(!q.empty()){
            ret.push_back(q.front());
            q.pop();
        }

        return ret;
    }
};