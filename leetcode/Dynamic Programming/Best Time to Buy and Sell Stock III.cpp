class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ti20 = 0, ti21 = INT_MIN, ti10 = 0, ti11 = INT_MIN;
        for(int price: prices){
            ti20 = max(ti20, ti21 + price);
            ti21 = max(ti21, ti10 - price);
            ti10 = max(ti10, ti11 + price);
            ti11 = max(ti11, -price);
        }
        return max(ti20, ti10);
    }
};