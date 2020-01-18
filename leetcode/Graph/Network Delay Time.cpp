class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> dist(N, INT_MAX);
        vector<bool> visit(N, false);
        unordered_map<int, vector<vector<int>>> graph;
        for(auto t: times){
            graph[t[0]-1].push_back({t[1]-1, t[2]});
        }

        visit[K-1] = true;
        dist[K-1] = 0;
        for(auto n: graph[K-1])
            dist[n[0]] = n[1];

        for(int i = 1; i < N; ++i){
            int u = -1, md = INT_MAX;
            for(int j = 0; j < N; ++j){
                if(!visit[j] && dist[j] < md){
                    u = j;
                    md = dist[j];
                }
            }

            if(u == -1)
                continue;

            visit[u] = true;

            if(graph.find(u) == graph.end())
                continue;

            for(auto n: graph[u]){
                if(!visit[n[0]] && md + n[1] < dist[n[0]])
                    dist[n[0]] = md + n[1];
            }
        }

        int ret = 0;
        for(int i = 0; i < N; ++i){
            if(!visit[i])
                return -1;
            ret = max(ret, dist[i]);
        }

        return ret;
    }
};