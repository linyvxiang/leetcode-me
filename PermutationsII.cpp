class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > ret;
        vector<int> cur_ret;
        vector<bool> visited(nums.size(), false);
        sort(nums.begin(), nums.end());
        generate_permutition(nums, cur_ret, ret, visited);
        return ret;
    }
private:
    void generate_permutition(const vector<int>& nums,
                              vector<int>& cur_ret,
                              vector<vector<int> >& ret,
                              vector<bool>& visited) {
        if (cur_ret.size() == nums.size()) {
            ret.push_back(cur_ret);
            return;
        }
        for (int pos = 0; pos < nums.size(); pos++) {
            if (pos > 0 && nums[pos - 1] == nums[pos] && visited[pos - 1]) {
                continue;
            }
            if (!visited[pos]) {
                visited[pos] = true;
                cur_ret.push_back(nums[pos]);
                generate_permutition(nums, cur_ret, ret, visited);
                cur_ret.pop_back();
                visited[pos] = false;
            }
        }
    }
};
