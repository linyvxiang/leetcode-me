class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> cur_ret;
        vector<bool> visited(nums.size(), false);
        sort(nums.begin(), nums.end());
        do_generate(nums, visited, cur_ret, ret);
        return ret;
    }
private:
    void do_generate(vector<int>& nums, vector<bool>& visited,
            vector<int>& cur_ret, vector<vector<int>>& ret) {
        if (cur_ret.size() == nums.size())  {
            ret.push_back(cur_ret);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i] ||
                    (i > 0 && nums[i] == nums[i - 1] && visited[i - 1])) {
                continue;
            }
            visited[i] = true;
            cur_ret.push_back(nums[i]);
            do_generate(nums, visited, cur_ret, ret);
            cur_ret.pop_back();
            visited[i] = false;
        }
    }
};
