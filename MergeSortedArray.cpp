class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int cur_pos = m + n - 1;
        int pos1 = m - 1;
        int pos2 = n - 1;
        while (pos1 >= 0 && pos2 >= 0) {
            if (nums1[pos1] > nums2[pos2]) {
                nums1[cur_pos--] = nums1[pos1--];
            } else {
                nums1[cur_pos--] = nums2[pos2--];
            }
        }
        if (pos2 >= 0) {
            while(pos2 >= 0) {
                nums1[cur_pos--] = nums2[pos2--];
            }
        }
    }
};
