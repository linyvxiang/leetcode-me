class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
        vector<int> tmp_res;

        if(!k)
            return res;
        do_generate_combine(n, k, 0, 1, res, tmp_res);
        return res;
    }
private:
    void do_generate_combine(int n, int k, int cur_len, int cur_pos,
                                vector<vector<int> > &res,
                                vector<int> &tmp_res)
  {
        if(cur_len == k) {
            res.push_back(tmp_res);
            return ;
        }
        if(cur_pos > n)
            return ;
        tmp_res.push_back(cur_pos);
        do_generate_combine(n, k, cur_len + 1, cur_pos + 1, res, tmp_res);
        tmp_res.pop_back();
        do_generate_combine(n, k, cur_len, cur_pos + 1, res, tmp_res);
    }
};
