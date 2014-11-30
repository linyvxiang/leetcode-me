class Solution {
public:
    int maxProfit(vector<int> &prices) {
		if(prices.empty() || prices.size() == 1)
			return 0;
		if(prices.size() == 2)
			return prices[1] > prices[0] ?
						prices[1] - prices[0] : 0;
		
		vector<int> left(prices.size());
		vector<int> right(prices.size());
		int i, v;
		for(i = 1, v = prices[0]; i < prices.size(); i++) {
			v = min(prices[i], v);
			left[i] = max(left[i - 1], prices[i] - v);
		}
		for(i = prices.size() - 2, v = prices[prices.size() - 1];
				i >= 0; i--) {
			v = max(prices[i], v);
			right[i] = max(right[i + 1], v - prices[i]);
		}
		int ret = 0;
		for(i = 0; i < prices.size(); i++)
			ret = max(ret, left[i] + right[i]);

		return ret;
    }
};
