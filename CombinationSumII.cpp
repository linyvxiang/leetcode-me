class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> cur_ret;
        vector<vector<int> > ret;
        if (candidates.empty()) {
            return ret;
        }
        sort(candidates.begin(), candidates.end());
        generate_combinations(candidates, 0, 0, target, cur_ret, ret);
        return ret;
    }
private:
    void generate_combinations(const vector<int>& nums,
                               int cur_pos, int cur_sum,
                               int target, vector<int>& cur_ret,
                               vector<vector<int> >& ret) {
        if (cur_sum == target) {
            ret.push_back(cur_ret);
        }
        for (int pos = cur_pos; pos < nums.size(); pos++) {
            if (pos != cur_pos && nums[pos] == nums[pos - 1]) {
                continue;
            }
            if (cur_sum + nums[pos] > target) {
                continue;
            }
            cur_ret.push_back(nums[pos]);
            generate_combinations(nums, pos + 1, cur_sum + nums[pos], target, cur_ret, ret);
            cur_ret.pop_back();
        }
    }
};
