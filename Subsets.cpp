class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > ret;
        vector<int> cur_ret;
        sort(nums.begin(), nums.end());
        generate_subsets(nums, 0, cur_ret, ret);
        return ret;
    }
private:
        void generate_subsets(const vector<int>& nums, int cur_pos,
                vector<int>& cur_ret, vector<vector<int> >& ret) {
            if (cur_pos == nums.size()) {
                ret.push_back(cur_ret);
                return ;
            }
            cur_ret.push_back(nums[cur_pos]);
            generate_subsets(nums, cur_pos + 1, cur_ret, ret);
            cur_ret.pop_back();
            generate_subsets(nums, cur_pos + 1, cur_ret, ret);
        }
};

