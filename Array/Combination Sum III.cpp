class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        bt(k, n, vector<int>(), 0, 1);
        return ret;
    }

    void bt(int k, int n, vector<int> cur, int sum, int start){
        if(sum > n)
            return;
        if(cur.size() == k)
        {
            if(sum == n)
                ret.push_back(cur);
            return;
        }

        for(int i = start; i <= 9; ++i){
            cur.push_back(i);
            bt(k, n, cur, sum+i, i+1);
            cur.pop_back();
        }
    }

private:
    vector<vector<int>> ret;
};