using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        }
        vector<int> diff(prices.size() - 1);
        for (int i = 1; i < prices.size(); i++) {
            diff[i - 1] = prices[i] - prices[i - 1];
        }
        int max_profit = 0;
        for (int i = 0; i < diff.size(); i++) {
            if (diff[i] > 0) {
                max_profit += diff[i];
            }
        }
        return max_profit;
     }
};
