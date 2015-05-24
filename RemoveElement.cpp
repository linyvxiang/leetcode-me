class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) {
            return 0;
        }
        int slow = -1;
        int fast = 0;
        for (; fast < nums.size(); fast++) {
            if (nums[fast] != val) {
                nums[++slow] = nums[fast];
            }
        }
        return slow + 1;
    }
};
