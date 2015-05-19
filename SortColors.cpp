class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start_pos = -1;
        int end_pos = nums.size();
        int cur_pos = 0;
        while (cur_pos < end_pos) {
            if (cur_pos > start_pos && nums[cur_pos] == 0) {
                swap(nums[++start_pos], nums[cur_pos]);
            } else if (cur_pos < end_pos && nums[cur_pos] == 2) {
                swap(nums[--end_pos], nums[cur_pos]);
            } else {
                cur_pos++;
            }
        }
    }
};
