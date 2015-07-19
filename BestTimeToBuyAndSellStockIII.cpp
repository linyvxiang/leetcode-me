class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        vector<int> left_min(prices.size());
        vector<int> right_max(prices.size());
        vector<int> left_max_profit(prices.size());
        vector<int> right_max_profit(prices.size());
        left_min[0] = prices[0];
        right_max[prices.size() - 1] = prices[prices.size() - 1];
        left_max_profit[0] = 0;
        right_max_profit[prices.size() - 1] = 0;
        for (int i = 1; i < prices.size(); i++) {
            left_min[i] = min(prices[i], left_min[i - 1]);
            left_max_profit[i] = max(left_max_profit[i - 1],
                                    prices[i] - left_min[i]);
        }
        for (int i = prices.size() - 2; i >= 0; i--) {
            right_max[i] = max(prices[i], right_max[i + 1]);
            right_max_profit[i] = max(right_max_profit[i + 1],
                                    right_max[i] - prices[i]);
        }
        int max_profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            max_profit = max(max_profit,
                    left_max_profit[i] + right_max_profit[i]);
        }
        return max_profit;
    }
};
