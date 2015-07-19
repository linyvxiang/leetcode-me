class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        vector<int> min_price(prices.size());
        min_price[0] = prices[0];
        int max_profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            min_price[i] = min(min_price[i - 1], prices[i]);
            max_profit = max(max_profit, prices[i] - min_price[i]);
        }
        return max_profit;
    }
};
