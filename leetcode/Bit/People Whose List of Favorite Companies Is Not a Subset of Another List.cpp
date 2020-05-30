class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        unordered_map<string, long long> bmap1, bmap2;
        int n = favoriteCompanies.size();

        for(int i = 0; i < n; ++i){
            for(string& c: favoriteCompanies[i]){
                if(i < 60) bmap1[c] |= 1LL << i;
                else bmap2[c] |= 1LL << (i - 60);
            }
        }

        vector<int> ret;
        for(int i = 0; i < n; ++i){
            long long b1 = (1LL << 60) - 1;
            long long b2 = b1;
            for(string& c: favoriteCompanies[i]){
                b1 &= bmap1[c];
                b2 &= bmap2[c];
            }

            if(__builtin_popcountll(b1) + __builtin_popcountll(b2) == 1)
                ret.push_back(i);
        }

        return ret;
    }
};