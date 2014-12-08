class Solution {
	public:
		int maxProfit(vector<int> &prices) {
			if(prices.empty() || prices.size() == 1)
				return 0;
			prices.insert(prices.begin(), prices[0]);
			vector<int> left_min(prices.size(), 0);
			left_min[0] = prices[0];
			int ret = 0;
			for(size_t i = 1; i < prices.size(); i++) {
				left_min[i] = min(left_min[i - 1], prices[i]);
				if(prices[i] > left_min[i])
					ret = max(ret, prices[i] - left_min[i]);
			}
			return ret;
		}
};
