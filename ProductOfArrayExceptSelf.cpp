class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long all_prod = 1;
        bool zero_exist = false;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                all_prod *= nums[i];
            } else {
                if (!zero_exist) {
                    zero_exist = true;
                } else {
                    all_prod = 0;
                    break;
                }
            }
        }
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            if (zero_exist) {
                if (nums[i] != 0) {
                    result.push_back(0);
                } else {
                    result.push_back(all_prod);
                }
            } else {
                result.push_back(all_prod / nums[i]);
            }
        }
        return result;
    }
};
