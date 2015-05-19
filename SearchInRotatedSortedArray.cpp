class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binary_search(nums, 0, nums.size() - 1, target);
    }
private:
    int binary_search(const vector<int>& nums, int start, int end, int target) {
        if (start > end) {
            return -1;
        }
        if (start == end || start == end - 1) {
            if (target == nums[start]) {
                return start;
            } else if (target == nums[end]) {
                return end;
            } else {
                return -1;
            }
        }
        int mid = (start + end) / 2;
        if (target == nums[mid]) {
            return mid;
        }
        if (nums[mid] >= nums[start] && nums[mid] >= nums[end]) {
            if (target >= nums[start] && target <= nums[mid]) {
                return binary_search(nums, start, mid, target);
            } else {
                return binary_search(nums, mid, end, target);
            }
        } else if (nums[mid] < nums[start] && nums[mid] < nums[end]) {
            if (target >= nums[mid] && target <= nums[end]) {
                return binary_search(nums, mid, end, target);
            } else {
                return binary_search(nums, start, mid, target);
            }
        } else {
            if (target > nums[mid]) {
                return binary_search(nums, mid + 1, end, target);
            } else {
                return binary_search(nums, start, mid - 1, target);
            }
        }
    }
};
