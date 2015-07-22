class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur_ret;
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        do_generate(0, nums, cur_ret, ret);
        return ret;
    }
private:
    void do_generate(int cur_pos, vector<int>& nums,
            vector<int>& cur_ret, vector<vector<int>>& ret) {
        if (cur_pos == nums.size()) {
            ret.push_back(cur_ret);
            return;
        }
        cur_ret.push_back(nums[cur_pos]);
        do_generate(cur_pos + 1, nums, cur_ret, ret);
        cur_ret.pop_back();
        do_generate(cur_pos + 1, nums, cur_ret, ret);
    }
};
