class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int cur_pos = 0;
        while (cur_pos < prices.size()) {
            int next_pos = cur_pos + 1;
            while (next_pos < prices.size() &&
                    prices[next_pos] > prices[next_pos - 1]) {
                next_pos++;
            }
            max_profit += prices[next_pos - 1] - prices[cur_pos];
            cur_pos = next_pos;
        }
        return max_profit;
    }
};
