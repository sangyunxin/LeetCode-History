class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 递推公式:
        // buy[i] = max(sell[i-2]-prices[i], buy[i-1]);
        // sell[i] = max(buy[i-1]+prices[i], sell[i-1]);

        int prev_sell = 0, sell = 0, buy = INT_MIN, prev_buy;
        for(int price: prices){
            prev_buy = buy;
            buy = max(prev_sell - price, prev_buy);
            prev_sell = sell;
            sell = max(prev_buy + price, prev_sell);
        }

        return sell;
    }
};