class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > ret;
        vector<int> cur_ret;
        if (nums.size() < 3) {
            return ret;
        }
        sort(nums.begin(), nums.end());
        int cur_pos = 0;
        while (cur_pos < nums.size() - 2) {
            int start = cur_pos + 1;
            int end = nums.size() - 1;
            while (start < end) {
                int cur_sum = nums[start] + nums[end] + nums[cur_pos];
                if (cur_sum == 0) {
                    cur_ret.push_back(nums[cur_pos]);
                    cur_ret.push_back(nums[start]);
                    cur_ret.push_back(nums[end]);
                    ret.push_back(cur_ret);
                    cur_ret.clear();
                    start++;
                    while (start < end && nums[start] == nums[start - 1]) {
                        start++;
                    }
                    end--;
                    while (start < end && nums[end] == nums[end + 1]) {
                        end--;
                    }
                } else if (cur_sum > 0) {
                    end--;
                    while (start < end && nums[end] == nums[end + 1]) {
                        end--;
                    }
                } else {
                    start++;
                    while (start < end && nums[start] == nums[start - 1]) {
                        start++;
                    }
                }
            }
            cur_pos++;
            while (cur_pos < nums.size() - 2 &&
                    nums[cur_pos] == nums[cur_pos - 1]) {
                cur_pos++;
            }
        }
        return ret;
    }
};
