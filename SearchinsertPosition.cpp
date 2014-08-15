class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int res = -1;
        int start = 0, end = n - 1;
        while(start <= end) {
            int mid = (start + end) >> 1;
            if(A[mid] == target)
                return mid;
            if(A[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
};
