class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.empty())
            return 0;
        int n = prices.size();
        vector<int> f(n, 0);
        vector<int> g(n, 0);
        int i, p, v;
        for(i = 1, v = prices[0]; i < n; i++) {
            v = min(v, prices[i]);
            f[i] = max(f[i - 1], prices[i] - v);
        }
        for(i = n - 2, p = prices[n - 1]; i >= 0; i--) {
            p = max(p, prices[i]);
            g[i] = max(g[i + 1], p - prices[i]);
        }
        int max_sum = 0;
        for(i = 0; i < n; i++)
            max_sum = max(max_sum, f[i] + g[i]);
        return  max_sum;
    }
};
