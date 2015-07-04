class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return do_find_k(nums, 0, nums.size() - 1, k);
    }
private:
    int do_find_k(vector<int>& nums, int l, int r, int k) {
        if (l == r) {
            return nums[l];
        }
        int i = l;
        int j = r;
        int x = nums[l];
        while (i < j) {
            while (i < j && nums[j] >= x) {
                j--;
            }
            if (i < j) {
                nums[i++] = nums[j];
            }
            while (i < j && nums[i] < x) {
                i++;
            }
            if (i < j) {
                nums[j--] = nums[i];
            }
        }
        nums[i] = x;
        if (r - i + 1 == k) {
            return nums[i];
        } else if (r - i + 1 < k) {
            return do_find_k(nums, l, i - 1, k - r + i - 1);
        } else {
            return do_find_k(nums, i + 1, r, k);
        }
    }
};
