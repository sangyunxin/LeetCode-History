class Solution {
public:
    map<string, vector<pair<string, double>>> g;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ret;
        for(int i = 0; i < equations.size(); ++i){
            g[equations[i][0]].push_back({equations[i][1], values[i]});
            g[equations[i][1]].push_back({equations[i][0], 1 / values[i]});
        }

        for(auto q: queries){
            double val = -1;
            unordered_set<string> visit;
            visit.insert(q[0]);
            if(g.find(q[0]) != g.end() && g.find(q[1]) != g.end())
                val = dfs(q[0], q[1], visit);
            ret.push_back(val);
        }
        return ret;
    }

    double dfs(string& start, string& end, unordered_set<string>& visit){
        // cout << start << "," << end << endl;
        if(start == end)
            return 1;

        for(auto next: g[start]){
            if(visit.find(next.first) != visit.end())
                continue;
            visit.insert(next.first);
            double flag = dfs(next.first, end, visit);
            if(flag != -1)
                return next.second * flag;
        }

        return -1;
    }
};