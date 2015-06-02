class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        vector<vector<int> > ret;
        if (nums.size() < 4) {
            return ret;
        }
        sort(ret.begin(), ret.end());
        unordered_multimap<int, pair<int, int> > two_sum_map;
        for (int i = 0; i + 1 < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                two_sum_map.insert(make_pair(nums[i] + nums[j], make_pair(i, j)));
            }
        }
        for (auto i = two_sum_map.begin(); i != two_sum_map.end(); ++i) {
            auto j = two_sum_map.equal_range(target - i->first);
            for (auto it = j.first; it != j.second; ++it) {
                int a = i->second.first;
                int b = i->second.second;
                int c = it->second.first;
                int d = it->second.second;
                if (a != c && a != d && b != c && b != d) {
                    vector<int> cur_ret = { nums[a], nums[b], nums[c], nums[d] };
                    sort(cur_ret.begin(), cur_ret.end());
                    ret.push_back(cur_ret);
                }
            }
        }
        sort(ret.begin(), ret.end());
        ret.erase(unique(ret.begin(), ret.end()), ret.end());
        return ret;
    }
};
