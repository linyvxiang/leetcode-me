class Solution {
public:
    int search(vector<int>& nums, int target) {
        return do_search(0, nums.size() - 1, nums, target);
    }
private:
    int do_search(int start, int end,
            const vector<int>& nums, int target) {
        if (start > end) {
            return -1;
        }
        int mid = (start + end) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[start] <= target && target <= nums[mid]) {
            return do_search(start, mid - 1, nums, target);
        } else if (nums[mid] <= target && target <= nums[end]) {
            return do_search(mid + 1, end, nums, target);
        } else {
            int left = do_search(start, mid - 1, nums, target);
            return left != -1 ? left : do_search(mid + 1, end, nums, target);
        }
    }
};
