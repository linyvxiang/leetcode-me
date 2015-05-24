class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.empty()) {
            return 1;
        }
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] >= 0 && nums[i] < nums.size() && nums[nums[i]] != nums[i]) {
                swap(nums[i], nums[nums[i]]);
            } else {
                i++;
            }
        }
        for (i = 1; i < nums.size(); i++) {
            if (nums[i] != i) {
                return i;
            }
        }
        if (nums[0] == nums.size()) {
            return nums[0] + 1;
        } else {
            return nums.size();
        }
    }
};
