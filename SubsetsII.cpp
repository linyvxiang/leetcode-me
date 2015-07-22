class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> cur_ret;
        vector<vector<int>> ret;
        do_generate(0, nums, cur_ret, ret);
        return ret;
    }
private:
    void do_generate(int cur_pos, vector<int>& nums,
            vector<int>& cur_ret, vector<vector<int>>& ret) {
        ret.push_back(cur_ret);
        for (int pos = cur_pos; pos < nums.size(); pos++) {
            if (pos > cur_pos && nums[pos] == nums[pos - 1]) {
                continue;
            }
            cur_ret.push_back(nums[pos]);
            do_generate(pos + 1, nums, cur_ret, ret);
            cur_ret.pop_back();
        }
    }
};
