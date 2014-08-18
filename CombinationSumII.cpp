class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > res;
        vector<int> tmp_res;
        if(num.empty())
            return res;
        sort(num.begin(), num.end());
        do_generate_combination(num, 0, 0, target, res, tmp_res);
        return res;
    }
private:
    void do_generate_combination(vector<int> &num, int cur_pos, int cur_sum, int target,
                                    vector<vector<int> > &res, vector<int> &tmp_res)
    {
        if(cur_sum > target || cur_pos > num.size())
            return ;
        if(cur_sum == target) {
            res.push_back(tmp_res);
            return ;
        }
        int start;
        for(start = cur_pos; start < num.size(); start++) {
            if(start > cur_pos && num[start] == num[start - 1])
                continue;
            tmp_res.push_back(num[start]);
            do_generate_combination(num, start + 1, cur_sum + num[start],
                                        target, res, tmp_res);
            tmp_res.pop_back();
        }
    }
};
