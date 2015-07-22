class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> cur_ret;
        vector<vector<int>> ret;
        do_combination(1, 0, k, n, cur_ret, ret);
        return ret;
    }
private:
    void do_combination(int cur_pos, int cur_sum, int k,
                        int target, vector<int>& cur_ret,
                        vector<vector<int>>& ret) {
        if (cur_ret.size() == k) {
            if (cur_sum == target) {
                ret.push_back(cur_ret);
            }
            return;
        }
        for (int pos = cur_pos; pos <= 9; pos++) {
            cur_ret.push_back(pos);
            do_combination(pos + 1, cur_sum + pos,
                            k, target, cur_ret, ret);
            cur_ret.pop_back();
        }
    }
};
