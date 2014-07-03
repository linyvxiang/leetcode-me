class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int i, max = 0;
        vector<int> diff;
        vector<int> res;
        diff.push_back(0);
        res.push_back(0);
        for(i = 1; i < prices.size(); i++)
            diff.push_back(prices[i] - prices[i - 1]);
        for(i = 1; i < diff.size(); i++) {
            int temp;
            if(res[res.size() - 1] > 0)
                temp = res[res.size() - 1] + diff[i];
            else
                temp = diff[i];
            res.push_back(temp);
            if(max < temp)
                max = temp;
                
        }
        return max;
    }
};
