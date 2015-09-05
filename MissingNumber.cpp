class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int cur_pos = 0;
        int len = nums.size();
        while (cur_pos < len) {
            if (0 <= nums[cur_pos] && nums[cur_pos] < len &&
                    nums[cur_pos] != cur_pos &&
                    nums[nums[cur_pos]] != nums[cur_pos]) {
                swap(nums[cur_pos], nums[nums[cur_pos]]);
            } else {
                cur_pos++;
            }
        }
        for (int i = 0; i < len; i++) {
            if (nums[i] != i) {
                return i;
            }
        }
        return len;
    }
};
