class Solution {
public:
    int numJewelsInStones(string J, string S) {
        vector<int> count(52, 0);
        for(char c: S){
            if(c >= 'A' && c <= 'Z')
                count[c-'A'+26]++;
            else
                count[c-'a']++;
        }
        int ret = 0;
        for(char c: J){
            if(c >= 'A' && c <= 'Z')
                ret += count[c-'A'+26];
            else
                ret += count[c-'a'];
        }
        return ret;
    }
};