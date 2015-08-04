class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int cur_sum = 0;
        int cur_start = 0;
        int cur_end = 0;
        int min_len = INT_MAX;
        while (cur_start < nums.size()) {
            while (cur_end < nums.size() && cur_sum < s) {
                cur_sum += nums[cur_end];
                cur_end++;
            }
            if (cur_sum >= s) {
                min_len = min(min_len, cur_end - cur_start);
            }
            cur_sum -= nums[cur_start];
            cur_start++;
        }
        return min_len == INT_MAX ? 0 : min_len;
    }
};
