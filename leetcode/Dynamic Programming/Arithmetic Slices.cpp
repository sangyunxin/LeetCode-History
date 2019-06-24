class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        int i = 1, l = 2, ret = 0;

        for(int i = 1; i < n - 1; ++i){
            if(A[i] - A[i-1] == A[i+1] - A[i])
                l++;
            else if(l > 2){
                ret += (l-2) * (l-1) / 2;
                l = 2;
            }
        }

        ret += (l-2) * (l-1) / 2;

        return ret;
    }
};