class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
        vector<int> tmp;
        generate_combines(1, 0, n, k, tmp, res);
        return res;
    }
private:
    void generate_combines(int cur_pos, int numbers, int n, int k,
                            vector<int> &tmp, vector<vector<int> > &res)
    {
        if(numbers > k || cur_pos > n + 1)
            return ;
        if(numbers == k) {
            res.push_back(tmp);
            return ;
        }
        tmp.push_back(cur_pos);
        generate_combines(cur_pos + 1, numbers + 1, n, k, tmp, res);
        tmp.pop_back();
        generate_combines(cur_pos + 1, numbers, n, k, tmp, res);
    }
};
