class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> cur_ret;
        vector<bool> visited(nums.size(), false);
        do_generate(nums, visited, cur_ret, ret);
        return ret;
    }
private:
    void do_generate(vector<int>& nums, vector<bool>& visited,
                     vector<int>& cur_ret, vector<vector<int>>& ret) {
        if (cur_ret.size() == nums.size()) {
            ret.push_back(cur_ret);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                cur_ret.push_back(nums[i]);
                do_generate(nums, visited, cur_ret, ret);
                cur_ret.pop_back();
                visited[i] = false;
            }
        }
    }
};
