#include <iostream>
#include <vector>
using namespace std;
class Solution {
	public:
		int maxProfit(vector<int> &prices) {
			if(prices.empty() || prices.size() == 1)
				return 0;
			int ret = 0, pre_price = prices[0];
			prices.insert(prices.end(), 0);
			for(size_t i = 1; i < prices.size(); i++) {
				if(prices[i] < prices[i - 1]) {
					ret += prices[i - 1] - pre_price;
					pre_price = prices[i];
				}
			}
			return ret;
		}
};

int main()
{
	vector<int> price;
	price.push_back(1);
	price.push_back(4);
	price.push_back(2);
	Solution s;
	cout << s.maxProfit(price) << endl;
}
