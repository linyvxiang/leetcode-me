class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            if (nums.size() == 1) {
                return nums[0];
            }
            int max_val = INT_MIN;
            int positive_max = 0;
            int negative_min = 0;
            for (int i = 0; i < nums.size(); i++) {
                int m = positive_max;
                int n = negative_min;
                if (nums[i] > 0) {
                    positive_max = max(nums[i] * m, nums[i]);
                    negative_min = min(nums[i] * n, 0);
                } else if (nums[i] < 0){
                    positive_max = max(nums[i] * n, 0);
                    negative_min = min(nums[i] * m, nums[i]);
                } else {
                    positive_max = 0;
                    negative_min = 0;
                }
                max_val = max(max_val, positive_max);
            }
            return max_val;
        }
};
