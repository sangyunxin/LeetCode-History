class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        int ret = 10, cnt = 9;
        for(int i = 2; i <= n; i++){
            if(i == 11)
                break;
            cnt *= (11 - i);
            ret += cnt;
        }

        return ret;
    }
};