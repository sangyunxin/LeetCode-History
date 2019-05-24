class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int n = A.size();
        vector<vector<int>> m(n, vector<int>(26, 0));
        vector<string> ret;

        for(int i = 0; i < n; ++i)
            for(char c: A[i])
                m[i][c-'a']++;

        for(int i = 0; i < 26; i++)
        {
            int count = INT_MAX;
            for(int j = 0; j < n; j++)
                count = min(m[j][i], count);

            for(int k = 0; k < count; ++k)
                ret.push_back(string(1, 'a' + i));
        }

        return ret;
    }
};