class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        vector<int> left_min(prices.size());
        vector<int> right_max(prices.size());
        left_min[0] = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            left_min[i] = min(left_min[i - 1], prices[i]);
        }
        right_max[prices.size() - 1] = prices[prices.size() - 1];
        for (int i = prices.size() - 2; i >= 0; i--) {
            right_max[i] = max(right_max[i + 1], prices[i]);
        }
        vector<int> left_profit(prices.size());
        vector<int> right_profit(prices.size());
        left_profit[0] = 0;
        for (int i = 1; i < prices.size(); i++) {
            left_profit[i] = max(prices[i] - left_min[i], left_profit[i - 1]);
        }
        right_profit[prices.size() - 1] = 0;
        for (int i = prices.size() - 2; i >= 0; i--) {
            right_profit[i] = max(right_max[i] - prices[i], right_profit[i + 1]);
        }
        int max_pro = 0;
        for (int i = 0; i < prices.size(); i++) {
            max_pro = max(max_pro, left_profit[i] + right_profit[i]);
        }
        return max_pro;
    }
};