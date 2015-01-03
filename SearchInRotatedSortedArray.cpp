class Solution {
    public:
        int search(int A[], int n, int target) {
            return binary_search(A, 0, n - 1, target);
        }
    private:
        int binary_search(int A[], int start, int end, int target)
        {
            if(start > end)
                return -1;
            int mid = (start + end) >> 1;
            if(A[mid] == target)
                return mid;
            if(A[start] <= A[mid]) {
                if(A[start] <= target && target <= A[mid])
                    return binary_search(A, start, mid - 1, target);
                else
                    return binary_search(A, mid + 1, end, target);
            } else {
                if(A[mid] <= target && target <= A[end])
                    return binary_search(A, mid + 1, end, target);
                else
                    return binary_search(A, start, mid - 1, target);
            }
        }
};
