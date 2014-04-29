class Solution {
public:
    void do_slove(vector<vector<int>> &res, vector<int> &cur_res, vector<int> num, int cur_sum, int cur_pos, int target)
    {
        if(cur_sum == target) {
            res.push_back(cur_res);
            return ;
        }
        if(cur_sum > target)
            return ;
        int prev = -1, i;
        for(i = cur_pos; i < num.size(); i++) {
            if(prev == num[i]) continue;
            cur_res.push_back(num[i]);
            prev = num[i];
            do_slove(res, cur_res, num, cur_sum + num[i], i, target);
            cur_res.pop_back();
        }
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur_res;
        vector<int> new_candidates;
        int prev = -1, i;
        for(i = 0; i < candidates.size(); i++) {
            if(prev == candidates[i])
                continue;
            new_candidates.push_back(candidates[i]);
            prev = candidates[i];
        }
        sort(new_candidates.begin(), new_candidates.end());
        do_slove(res, cur_res, new_candidates, 0, 0, target);
        return res;
    }
};
