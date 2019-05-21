class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> ret;
        for(int a: A)
            ret.push_back(a * a);
        sort(ret.begin(), ret.end());
        return ret;
    }
};