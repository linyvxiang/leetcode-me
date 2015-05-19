class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return check_exist(nums, 0, nums.size() - 1, target);
    }
private:
    bool check_exist(const vector<int>& nums, int start, int end, int target) {
        if (start > end) {
            return false;
        }
        int mid = (start + end) / 2;
        if (nums[mid] == target) {
            return true;
        }
        if (nums[start] == nums[mid]) {
            return check_exist(nums, start + 1, end, target);
        } else if (nums[end] == nums[mid]) {
            return check_exist(nums, start, end - 1, target);
        } else if (nums[start] < nums[mid]) {
            if (target >= nums[start] && target < nums[mid]) {
                return check_exist(nums, start, mid - 1, target);
            } else {
                return check_exist(nums, mid + 1, end, target);
            }
        } else {
            if (target > nums[mid] && target <= nums[end]) {
                return check_exist(nums, mid + 1, end, target);
            } else {
                return check_exist(nums, start, mid - 1, target);
            }
        }
    }
};
