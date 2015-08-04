class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int first_pos = nums.size() - 2;
        while (first_pos >= 0 && nums[first_pos] >= nums[first_pos + 1]) {
            first_pos--;
        }
        if (first_pos < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int second_pos = nums.size() - 1;
        while (second_pos >= first_pos && nums[second_pos] <= nums[first_pos]) {
            second_pos--;
        }
        swap(nums[first_pos], nums[second_pos]);
        reverse(nums.begin() + first_pos + 1, nums.end());
    }
};
