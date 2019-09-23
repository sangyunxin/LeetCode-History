class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int ps = 1, ph = 0, n = A.size();
        for(int i = 1; i < n; ++i){
            int ns = n, nh = n;
            if(A[i] > A[i-1] && B[i] > B[i-1]){
                ns = ps + 1;
                nh = ph;
            }
            
            if(A[i] > B[i-1] && B[i] > A[i-1]){
                ns = min(ns, ph + 1);
                nh = min(nh, ps);
            }
            
            ps = ns;
            ph = nh;
        }
        
        return min(ps, ph);
    }
};