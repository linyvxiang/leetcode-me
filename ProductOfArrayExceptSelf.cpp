class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1);
        long long prod = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            prod *= nums[i];
            result[i + 1] = prod;
        }
        prod = 1;
        for (int i = nums.size() - 1; i > 0; i--) {
            prod *= nums[i];
            result[i - 1] *= prod;
        }
        return result;
    }
};
