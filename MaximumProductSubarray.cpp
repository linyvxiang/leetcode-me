class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int max_prod = INT_MIN;
        int max_positive = 0;
        int min_negative = 0;
        for (int i = 0; i < nums.size(); i++) {
            int m = max_positive;
            int n = min_negative;
            if (nums[i] > 0) {
                max_positive = max(m * nums[i], nums[i]);
                min_negative = min(n * nums[i], 0);
            } else if (nums[i] < 0) {
                max_positive = max(n * nums[i], 0);
                min_negative = min(m * nums[i], nums[i]);
            } else {
                max_positive = 0;
                min_negative = 0;
            }
            max_prod = max(max_prod, max_positive);
        }
        return max_prod;
    }
};
