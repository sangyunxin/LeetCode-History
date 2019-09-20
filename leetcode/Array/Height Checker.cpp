class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int ret = 0;
        vector<int> q = heights;
        sort(q.begin(), q.end());
        for(int i = 0; i < q.size(); ++i){
            if(q[i] != heights[i])
                ret++;
        }
        return ret;
    }
};