class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> cur_ret;
        vector<vector<int>> ret;
        sort(candidates.begin(), candidates.end());
        do_combination(0, 0, target, candidates, cur_ret, ret);
        return ret;
    }
private:
    void do_combination(int cur_sum, int cur_pos, int target, 
            vector<int>& candidates, vector<int>& cur_ret,
            vector<vector<int>>& ret) {
        if (cur_sum > target) {
            return;
        }
        if (cur_sum == target) {
            ret.push_back(cur_ret);
            return;
        }
        for (int pos = cur_pos; pos < candidates.size(); pos++) {
            if (pos > cur_pos && candidates[pos - 1] == candidates[pos]) {
                continue;
            }
            cur_ret.push_back(candidates[pos]);
            do_combination(cur_sum + candidates[pos], pos + 1, target,
                    candidates, cur_ret, ret);
            cur_ret.pop_back();
        }
    }
};
