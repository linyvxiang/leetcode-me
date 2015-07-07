class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farest = 0;
        for (int i = 0; i < nums.size() && i <= farest; i++) {
            farest = max(farest, i + nums[i]);
            if (farest >= nums.size() - 1 || farest <= i) {
                break;
            }
        }
        return farest >= nums.size() - 1;
    }
};
