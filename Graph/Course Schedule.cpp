class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> degree(numCourses, 0);
        for(auto v: prerequisites){
            g[v[1]].push_back(v[0]);
            degree[v[0]]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; ++i)
            if(degree[i] == 0)
                q.push(i);

        int count = 0;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            count++;

            for(int next: g[cur])
                if(--degree[next] == 0)
                    q.push(next);
        }

        return count == numCourses;
    }
};