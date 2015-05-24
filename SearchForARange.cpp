class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret;
        if (nums.empty()) {
            ret.push_back(-1);
            ret.push_back(-1);
            return ret;
        }
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] == target) {
                int left = -1;
                find_left(nums, start, mid - 1, target, left);
                if (left == -1) {
                   left = mid; 
                }
                int right = -1;
                find_right(nums, mid + 1, end, target, right);
                if (right == -1) {
                    right = mid;
                }
                ret.push_back(left);
                ret.push_back(right);
                return ret;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        ret.push_back(-1);
        ret.push_back(-1);
        return ret;
    }
private:
    void find_left(const vector<int>& nums, int start,
                   int end, int target, int& ret) {
        if (start > end) {
            return;
        }
        int mid = (start + end) / 2;
        if (nums[mid] == target) {
            ret = mid;
            find_left(nums, start, mid - 1, target, ret);
        } else if (nums[mid] > target) {
            find_left(nums, start, mid - 1, target, ret);
        } else {
            find_left(nums, mid + 1, end, target, ret);
        }
    }
    void find_right(const vector<int>& nums, int start,
            int end, int target, int& ret) {
        if (start > end) {
            return;
        }
        int mid = (start + end) / 2;
        if (nums[mid] == target) {
            ret = mid;
            find_right(nums, mid + 1, end, target, ret);
        } else if (nums[mid] > target) {
            find_right(nums, start, mid - 1, target, ret);
        } else {
            find_right(nums, mid + 1, end, target, ret);
        }
    }
};
