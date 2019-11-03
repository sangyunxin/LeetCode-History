class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int xy = 0, yx = 0;
        for(int i = 0 ; i < s1.size(); ++i){
            if(s1[i] != s2[i]){
                if(s1[i] == 'x')
                    xy++;
                else
                    yx++;
            }
        }

        if((xy + yx) % 2 != 0)
            return -1;
        if(xy % 2 != 0)
            return (xy + yx) / 2 + 1;
        return (xy + yx) / 2;
    }
};