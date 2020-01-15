class Solution {
public:
    vector<string> ret;
    map<string, deque<string>> graph;

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto tk: tickets){
            graph[tk[0]].push_back(tk[1]);
        }
        for(auto it = graph.begin(); it != graph.end(); ++it){
            sort(it->second.begin(), it->second.end());
        }

        dfs("JFK");
        return ret;
    }

    void dfs(string start){
        while(graph[start].size()){
            string next = graph[start].front();
            graph[start].pop_front();
            dfs(next);
        }

        ret.insert(ret.begin(), start);
    }
};