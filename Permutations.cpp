class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > ret;
        vector<int> cur_ret;
        vector<bool> visited(nums.size(), false);
        generate_permution(nums, cur_ret, ret, visited);
        return ret;
    }
private:
    void generate_permution(const vector<int>& nums,
                            vector<int>& cur_ret,
                            vector<vector<int> >& ret,
                            vector<bool>& visited) {
        if (cur_ret.size() == nums.size()) {
            ret.push_back(cur_ret);
            return;
        }
        for (int pos = 0; pos < nums.size(); pos++) {
            if (!visited[pos]) {
                visited[pos] = true;
                cur_ret.push_back(nums[pos]);
                generate_permution(nums, cur_ret, ret, visited);
                cur_ret.pop_back();
                visited[pos] = false;
            }
        }
    }
};
