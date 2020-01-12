class Solution {
public:
    int minFlips(int a, int b, int c) {
        bitset<32> a2(a), b2(b), c2(c);
        int ret = 0;
        for(int i = 0; i < 32; ++i){
            if(c2[i] == 0){
                if(a2[i] == 1)
                    ret++;
                if(b2[i] == 1)
                    ret++;
            }else{
                if(a2[i] == b2[i] && a2[i] == 0)
                    ret++;
            }
        }
        return ret;
    }
};