class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.empty())
            return 0;
        vector<int> diff(prices.size() - 1, 0);
        int i;
        for(i = 1; i < prices.size(); i++)
            diff[i- 1] = prices[i] - prices[i - 1];
        diff.push_back(-1);
        int cur_res = 0, sum = 0;
        for(i = 0; i < diff.size(); i++) {
            if(diff[i] >= 0) {
                cur_res += diff[i];
            } else {
                sum += cur_res;
                cur_res = 0;
            }
        }
        return sum;
    }
};
