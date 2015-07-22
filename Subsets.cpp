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
        ret.push_back(cur_ret);
        for (int pos = cur_pos; pos < nums.size(); pos++) {
            cur_ret.push_back(nums[pos]);
            do_generate(pos + 1, nums, cur_ret, ret);
            cur_ret.pop_back();
        }
    }
};
