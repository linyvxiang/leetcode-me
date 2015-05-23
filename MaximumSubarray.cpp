class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> ret;
        int max_sum = nums[0];
        ret.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (ret[i - 1] >= 0) {
                ret.push_back(ret[i - 1] + nums[i]);
            } else {
                ret.push_back(nums[i]);
            }
            max_sum = max(max_sum, ret[i]);
        }
        return max_sum;
    }
};
