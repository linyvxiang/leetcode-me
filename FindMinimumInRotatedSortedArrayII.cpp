class Solution {
    public:
        int findMin(vector<int>& nums) {
            return find_min(nums, 0, nums.size() -1);
        }
    private:
        int find_min(const vector<int>& nums, int left, int right) {
            if (left == right) {
                return nums[left];
            } else if (left == right - 1) {
                return min(nums[left], nums[right]);
            }

            int mid = (left + right) / 2;
            if (nums[mid] == nums[left] && nums[mid] == nums[right]) {
                return min(find_min(nums, left, mid - 1), find_min(nums, mid + 1, right));
            } else if (nums[mid] != nums[left] && nums[mid] != nums[right]) {
                if (nums[mid] < nums[mid - 1] && nums[mid] < nums[mid + 1]) {
                    return nums[mid];
                } else if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                    return nums[mid + 1];
                } else {
                    return min(find_min(nums, left, mid - 1), find_min(nums, mid + 1, right));
                }
            } else if (nums[mid] == nums[mid - 1] && nums[mid] != nums[mid + 1]){
                if (nums[mid] > nums[mid + 1]) {
                    return nums[mid + 1];
                } else {
                    return min(find_min(nums, left, mid - 1), find_min(nums, mid + 1, right));
                }
            } else {
                if (nums[mid] < nums[mid - 1]) {
                    return nums[mid];
                } else {
                    return min(find_min(nums, left, mid - 1), find_min(nums, mid + 1, right));
                }
            }
        }
};
