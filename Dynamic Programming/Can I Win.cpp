class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(maxChoosableInteger >= desiredTotal)
            return true;
        if(maxChoosableInteger * (1 + maxChoosableInteger) / 2 < desiredTotal)
            return false;
        unordered_map<int, bool> m;
        return canWin(maxChoosableInteger, desiredTotal, 0, m);
    }

    bool canWin(int M, int T, int used, unordered_map<int, bool>& m){
        if(m.count(used)) return m[used];

        for(int i = 0; i < M; ++i){
            int cur = (1 << i);
            if((cur & used) == 0){
                if(i+1 >= T || !canWin(M, T-i-1, (cur | used), m)){
                    m[used] = true;
                    return true;
                }
            }
        }

        m[used] = false;
        return false;

    }
};