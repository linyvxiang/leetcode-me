class Solution {
public:
    int findMin(vector<int>& nums) {
        return find_min(nums, 0, nums.size() - 1);
    }
private:
    int find_min(const vector<int>& nums, int start, int end) {
        if (end - start + 1 < 3) {
            return min(nums[start], nums[end]);
        }
        int mid = (start + end) / 2;
        if (nums[mid] < nums[mid - 1] &&
                nums[mid] < nums[mid + 1]) {
            return nums[mid];
        } else if (nums[mid] > nums[mid - 1] &&
                nums[mid] > nums[mid + 1]) {
            return nums[mid + 1];
        } else {
            return min(find_min(nums, start, mid -1),
                    find_min(nums, mid + 1, end));
        }
    }
};
