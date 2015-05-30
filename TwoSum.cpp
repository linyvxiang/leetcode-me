class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int> > sorted_nums;
        for (int i = 0; i < nums.size(); i++) {
            sorted_nums.push_back(pair<int, int>(nums[i], i + 1));
        }
        sort(sorted_nums.begin(), sorted_nums.end());
        int start = 0;
        int end = sorted_nums.size() - 1;
        while (start < end) {
            int cur_sum = sorted_nums[start].first + sorted_nums[end].first;
            if (cur_sum == target) {
                vector<int> ret;
                ret.push_back(sorted_nums[start].second);
                ret.push_back(sorted_nums[end].second);
                sort(ret.begin(), ret.end());
                return ret;
            } else if (cur_sum > target) {
                end--;
            } else {
                start++;
            }
        }
    }
};
