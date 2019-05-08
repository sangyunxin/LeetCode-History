class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<int> d(numCourses, 0);
        vector<vector<int>> g(numCourses);
        for(auto p: prerequisites){
            d[p[0]]++;
            g[p[1]].push_back(p[0]);
        }

        queue<int> q;
        for(int i = 0; i < numCourses; ++i){
            if(d[i] == 0){
                q.push(i);
                res.push_back(i);
            }
        }

        while(!q.empty()){
            int cur = q.front();
            q.pop();

            for(int v: g[cur]){
                if(--d[v] == 0){
                    q.push(v);
                    res.push_back(v);
                }
            }
        }

        if(res.size() != numCourses)
            res.clear();
        return res;;
    }
};