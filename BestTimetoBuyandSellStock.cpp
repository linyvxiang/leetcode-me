class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.empty())
            return 0;
        int min_number = prices[0], cur_max = 0;
        int i;
        for(i = 1; i < prices.size(); i++) {
            if(prices[i] > min_number)
                cur_max = max(cur_max, prices[i] - min_number);
            if(prices[i] < min_number)
                min_number = prices[i];
        }
        return cur_max;
    }
};
