class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        set<int> s;
        for(int a: A){
            if(s.count(a) != 0)
                return a;
            s.insert(a);
        }
        return -1;
    }
};