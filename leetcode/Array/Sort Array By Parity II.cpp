class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int n = A.size();
        vector<int> ret(n);
        int o = 0, e = 1;
        for(int a: A)
        {
            if(a % 2 == 0){
                ret[o] = a;
                o += 2;
            }else{
                ret[e] = a;
                e += 2;
            }
        }

        return ret;
    }
};