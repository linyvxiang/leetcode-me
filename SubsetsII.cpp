class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > ret;
        vector<int> cur_ret;
        generate_subsets(S, 0, cur_ret, ret);
        return ret;
    }
private:
    void generate_subsets(const vector<int>& nums, int cur_pos,
            vector<int>& cur_ret, vector<vector<int> >& ret) {

        ret.push_back(cur_ret);

        int pos = cur_pos;
        for (; pos < nums.size(); pos++) {
            if (pos != cur_pos && nums[pos] == nums[pos - 1]) {
                continue;
            }
            cur_ret.push_back(nums[pos]);
            generate_subsets(nums, pos + 1, cur_ret, ret);
            cur_ret.pop_back();
        }
    }
};
