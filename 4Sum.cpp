class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        vector<vector<int> > ret;
        if (nums.size() < 4) {
            return ret;
        }
        sort(nums.begin(), nums.end());
        unordered_map<int, vector<pair<int, int> > > two_sum_map;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                two_sum_map[nums[i] + nums[j]].push_back(pair<int, int>(i, j));
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int key = target - nums[i] - nums[j];
                if (two_sum_map.find(key) == two_sum_map.end()) {
                    continue;
                }
                auto& vec = two_sum_map[key];
                for (int k = 0; k < vec.size(); k++) {
                    if (j >= vec[k].first) {
                        continue;
                    }
                    ret.push_back( { nums[i], nums[j], nums[vec[k].first], nums[vec[k].second] } );
                }
            }
        }
        sort(ret.begin(), ret.end());
        ret.erase(unique(ret.begin(), ret.end()), ret.end());
        return ret;
    }
};
