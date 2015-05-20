class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size()  == 1) {
            return true;
        }
        int max_len = 0;
        for (int i = 0; i < nums.size(); i++) {
            max_len = max(max_len, i + nums[i]);
            if (max_len >= nums.size() - 1) {
                return true;
            }
            if (max_len == i) {
                return false;
            }
        }
    }
};
