class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start = -1;
        int end = nums.size();
        int cur_pos = 0;
        while (cur_pos < end) {
            if (cur_pos > start && nums[cur_pos] == 0) {
                swap(nums[++start], nums[cur_pos]);
            } else if (cur_pos < end && nums[cur_pos] == 2) {
                swap(nums[--end], nums[cur_pos]);
            } else {
                cur_pos++;
            }
        }
    }
};
