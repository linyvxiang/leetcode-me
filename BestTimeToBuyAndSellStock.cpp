class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        vector<int> right_max(prices.size());
        right_max[right_max.size() - 1] = prices[prices.size() - 1];
        int max_profit = 0;
        for (int i = right_max.size() - 2; i >= 0; i--) {
            right_max[i] = max(right_max[i + 1], prices[i + 1]);
            max_profit = max(max_profit, right_max[i] - prices[i]);
        }
        return max_profit;
    }
};