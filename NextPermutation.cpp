class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int left_pos;
        for (left_pos = nums.size() - 2; left_pos >= 0; left_pos--) {
            if (nums[left_pos] < nums[left_pos + 1]) {
                break;
            }
        }
        if (left_pos < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int right_pos;
        for (right_pos = nums.size() - 1; right_pos >= 0; right_pos--) {
            if (nums[right_pos] > nums[left_pos]) {
                break;
            }
        }
        swap(nums[left_pos], nums[right_pos]);
        reverse(nums.begin() + left_pos + 1, nums.end());
    }
};
