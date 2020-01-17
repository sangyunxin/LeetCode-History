class Solution {
public:
    int find(vector<int>& parent, int i){
        if(parent[i] == 0) return i;
        return find(parent, parent[i]);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1, 0);
        vector<int> ret;
        for(auto e: edges){
            int x = find(parent, e[0]);
            int y = find(parent, e[1]);

            if(x == y) ret = e;
            else parent[x] = y;
        }
        return ret;
    }
};