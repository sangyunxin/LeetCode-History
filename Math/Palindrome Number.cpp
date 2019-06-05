class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int tmp = x;
        long ret = 0;
        while(tmp != 0){
            ret = ret * 10 + (tmp % 10);
            tmp /= 10;
        }
        if(ret == x)
            return true;
        return false;
    }
};