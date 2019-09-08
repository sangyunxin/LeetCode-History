class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int ti0 = 0, ti1 = INT_MIN;
        for(int price: prices){
            ti0 = max(ti0, ti1 + price);
            ti1 = max(ti1, ti0 - price - fee);
        }
        return ti0;
    }
};