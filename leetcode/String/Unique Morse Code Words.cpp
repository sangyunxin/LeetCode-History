class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string map[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> ret;
        for(string word: words){
            string cur = "";
            for(char c: word){
                cur += map[c - 'a'];
            }
            ret.insert(cur);
        }
        return ret.size();
    }
};