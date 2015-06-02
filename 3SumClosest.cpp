class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ret = 0x0fffffff;
        for (int cur_pos = 0; cur_pos < nums.size() - 2; cur_pos++) {
            int start = cur_pos + 1;
            int end = nums.size() - 1;
            while (start < end) {
                int cur_sum = nums[cur_pos] + nums[start] + nums[end];
                if (abs(cur_sum - target) < abs(ret - target)) {
                    ret = cur_sum;
                }
                if (cur_sum == target) {
                    return ret;
                } else if (cur_sum > target) {
                    end--;
                } else {
                    start++;
                }
            }
        }
        return ret;
    }
};
