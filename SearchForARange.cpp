class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret;
        if (nums.empty()) {
            ret.push_back(-1);
            ret.push_back(-1);
            return ret;
        }
        int left = find_lower_bound(nums, target);
        if (left >= nums.size() || nums[left] != target) {
            ret.push_back(-1);
            ret.push_back(-1);
            return ret;
        }
        int right = find_upper_bound(nums, target);
        ret.push_back(left);
        ret.push_back(right);
        return ret;
    }
private:
    int find_lower_bound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    int find_upper_bound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }
};
