class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.empty()) {
            return 1;
        }
        int cur_pos = 0;
        while (cur_pos < nums.size()) {
            if (0 < nums[cur_pos] && nums[cur_pos] <= nums.size() &&
                    nums[cur_pos] != cur_pos + 1 && 
                    nums[nums[cur_pos] - 1] != nums[cur_pos]) {
                swap(nums[cur_pos], nums[nums[cur_pos] - 1]);
            } else {
                cur_pos++;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};
