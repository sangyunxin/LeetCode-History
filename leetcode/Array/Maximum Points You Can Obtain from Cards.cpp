class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ret = 0, n = cardPoints.size();
        vector<int> csf(k+1, 0), csb(k+1, 0);
        for(int i = 1; i <= k; ++i){
            csf[i] = csf[i-1] + cardPoints[i-1];
            csb[i] = csb[i-1] + cardPoints[n-i];
        }

        for(int i = 0; i <= k; ++i){
            ret = max(ret, csf[i] + csb[k-i]);
        }

        return ret;
    }
};