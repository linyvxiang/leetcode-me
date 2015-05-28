class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int new_len = -1;
        int fast = 0;
        int slow = 0;
        while (slow < nums.size()) {
            while (fast < nums.size() && nums[slow] == nums[fast]) {
                fast++;
            }
            nums[++new_len] = nums[slow];
            slow = fast;
        }
        return new_len + 1;
    }
};
