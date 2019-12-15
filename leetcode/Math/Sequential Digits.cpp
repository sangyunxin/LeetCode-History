class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int n = 0, tmp = low;
        while(tmp){
            tmp = tmp / 10;
            n++;
        }

        int start = low / pow(10, n), cur = 0;
        vector<int> num, ret;
        for(int i = 0; i < n; ++i){
            cur = cur * 10 + start;
            num.push_back(start++);
        }

        while(cur < low){
            cur = helper(num);
        }

        while(cur < high){
            ret.push_back(cur);
            cur = helper(num);
        }

        return ret;
    }

    int helper(vector<int> & num){
        int n = num.size(), cur = 0;
        if(num[n-1] == 9){
            num.clear();
            for(int i = 1; i <= n + 1; ++i){
                cur = cur * 10 + i;
                num.push_back(i);
            }
            return cur;
        }

        for(int i = 0; i < n; ++i){
            num[i]++;
            cur = cur * 10 + num[i];
        }

        return cur;
    }
};