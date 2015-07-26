class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return do_search(0, nums.size() - 1, nums, target);
    }
private:
    bool do_search(int start, int end, const vector<int>& nums,
            const int& target) {
        if (start > end) {
            return false;
        }
        if (end - start <= 1) {
            return nums[start] == target ||
                    nums[end] == target;
        }
        int mid = (start + end) / 2;
        if (nums[mid] == target) {
            return true;
        }
        if (nums[start] <= target && nums[mid - 1] >= target) {
            return do_search(start, mid - 1, nums, target);
        } else if (nums[mid + 1] <= target && target <= nums[end]) {
            return do_search(mid + 1, end, nums, target);
        } else {
            bool left = do_search(start, mid - 1, nums, target);
            return left ? left : do_search(mid + 1, end, nums, target);
        }
    }
};
