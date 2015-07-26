class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lower_bound = find_lower_bound(nums, target);
        int upper_bound = find_upper_bound(nums, target);
        if (lower_bound <= upper_bound) {
            return vector<int> {lower_bound, upper_bound};
        } else {
            return vector<int> {-1, -1};
        }
    }
private:
    int find_lower_bound(const vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] == target) {
                end = mid - 1;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        cout << "start = " << start << endl;
        return start;
    }
    int find_upper_bound(const vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] == target) {
                start = mid + 1;
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        cout << "end = " << end << endl;
        return end;
    }
};
