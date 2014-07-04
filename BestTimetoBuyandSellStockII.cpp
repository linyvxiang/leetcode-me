class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int i, result = 0;
        vector<int> diff;
        vector<int> res;
        diff.push_back(0);
        res.push_back(0);
        for(i = 1; i < prices.size(); i++)
            diff.push_back(prices[i] - prices[i - 1]);
        for(i = 1; i < diff.size(); i++) {
            if(res[res.size() - 1] >= 0) {
                if(diff[i] >= 0)
                    result += diff[i];
                res.push_back(res[res.size() - 1] + diff[i]);
            } else {
                res.push_back(diff[i]);
                if(diff[i] >= 0)
                    result += diff[i];
            }
        }
        return result;
    }
};
