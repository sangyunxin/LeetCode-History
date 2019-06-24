class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> ret;
        int sum = 0;
        for(int a: A)
            if(a % 2 == 0)
                sum += a;

        for(int i = 0; i < queries.size(); ++i)
        {
            if(A[queries[i][1]] % 2 == 0 && (A[queries[i][1]] + queries[i][0]) % 2 == 0)
                sum += queries[i][0];
            else if(A[queries[i][1]] % 2 == 0 && (A[queries[i][1]] + queries[i][0]) % 2 != 0)
                sum -= A[queries[i][1]];
            else if(A[queries[i][1]] % 2 != 0 && (A[queries[i][1]] + queries[i][0]) % 2 == 0)
                sum += A[queries[i][1]] + queries[i][0];
            A[queries[i][1]] += queries[i][0];
            ret.push_back(sum);
        }

        return ret;
    }
};