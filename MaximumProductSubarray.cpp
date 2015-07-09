class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int max_prod = INT_MIN;
        int max_positive = 1;
        int min_negative = 1;
        for (int i = 0; i < nums.size(); i++) {
            int tmp_pos = max_positive;
            int tmp_neg = min_negative;
            max_positive = max(nums[i],
                    max(0, max(nums[i] * tmp_pos, nums[i] * tmp_neg)));
            min_negative = min(nums[i],
                    min(0, min(nums[i] * tmp_pos, nums[i] * tmp_neg)));
            max_prod = max(max_prod, max_positive);
        }
        return max_prod;
    }
};

