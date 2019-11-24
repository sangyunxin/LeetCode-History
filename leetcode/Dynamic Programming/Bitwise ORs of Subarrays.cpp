class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> res, cur;
        for(int a: A){
            unordered_set<int> tmp = {a};
            for(int c: cur) tmp.insert(c | a);
            cur = tmp;
            for(int c: cur) res.insert(c);
        }
        return res.size();
    }
};