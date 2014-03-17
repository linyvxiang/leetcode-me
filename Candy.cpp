class Solution {
public:
    int candy(vector<int> &ratings) {
        int n = ratings.size();
        int i, result = n;
        vector<int> incre(n);
        int inc = 1;
        for(i = 1; i < n; i++)
            if(ratings[i] > ratings[i - 1])
                incre[i] = max(inc++, incre[i]);
            else
                inc = 1;
        inc = 1;
        for(i = n - 2; i >= 0; i--)
            if(ratings[i] > ratings[i + 1])
                incre[i] = max(inc++, incre[i]);
            else
                inc = 1;
        for(i = 0; i < n; i++)
            result += incre[i];
        return result;
    }
};
