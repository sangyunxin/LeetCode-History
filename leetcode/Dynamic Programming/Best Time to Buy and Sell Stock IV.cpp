class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(k >= n / 2){
            int ti0 = 0, ti1 = INT_MIN;
            for(int price: prices){
                ti0 = max(ti0, ti1 + price);
                ti1 = max(ti1, ti0 - price);
            }
            return ti0;
        }else{
            vector<int> ti0(k+1, 0);
            vector<int> ti1(k+1, INT_MIN);
            for(int price: prices){
                for(int j = k; j >= 1; j--){
                    ti0[j] = max(ti0[j], ti1[j] + price);
                    ti1[j] = max(ti1[j], ti0[j-1] - price);
                }
            }
            return ti0[k];
        }
    }
};