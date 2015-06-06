class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int total = m + n;
        if (total % 2 == 1) {
            return do_find_kth(nums1, 0, m, nums2, 0, n, total / 2 + 1);
        } else {
            return (do_find_kth(nums1, 0, m, nums2, 0, n, total / 2) +
                   do_find_kth(nums1, 0, m, nums2, 0, n, total / 2 + 1)) * 0.5;
        }
    }
private:
    int do_find_kth(const vector<int>& nums1, int s1, int len1,
            const vector<int>& nums2, int s2, int len2, int k) {
        if (len1 <= 0) {
            return nums2[s2 + k - 1];
        }
        if (len2 <= 0) {
            return nums1[s1 + k- 1];
        }
        if (k <= 1) {
            return min(nums1[s1], nums2[s2]);
        }
        if (len1 / 2 + len2 / 2 + 1 >= k) {
            if (nums1[s1 + len1 / 2] > nums2[s2 + len2 / 2]) {
                return do_find_kth(nums1, s1, len1 - (len1 + 1) / 2, nums2, s2, len2, k);
            } else {
                return do_find_kth(nums1, s1, len1, nums2, s2, len2 - (len2 + 1) / 2, k);
            }
        } else {
            if (nums1[s1 + len1 / 2] > nums2[s2 + len2 / 2]) {
                return do_find_kth(nums1, s1, len1, nums2, s2 + (len2 + 1) / 2, len2 - (len2 + 1) / 2, k - (len2 + 1) / 2);
            } else {
                return do_find_kth(nums1, s1 + (len1 + 1) / 2, len1 - (len1 + 1) / 2, nums2, s2, len2, k - (len1 + 1) / 2);
            }
        }
    }
};
