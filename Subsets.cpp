class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > res;
        vector<int> tmp_res;
        if(S.empty())
            return res;
        sort(S.begin(), S.end());
        do_calc_subsets(S, 0, res, tmp_res);
        return res;
    }
private:
    void do_calc_subsets(vector<int> &S, int cur_pos,
                            vector<vector<int> > &res, vector<int> &tmp_res)
    {
        if(cur_pos == S.size()) {
            res.push_back(tmp_res);
            return ;
        }
        tmp_res.push_back(S[cur_pos]);
        do_calc_subsets(S, cur_pos + 1, res, tmp_res);
        tmp_res.pop_back();
        do_calc_subsets(S, cur_pos + 1, res, tmp_res);

    }
};
