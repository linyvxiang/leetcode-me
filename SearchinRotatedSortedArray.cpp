class Solution {
public:
    int search(int A[], int n, int target) {
        if(!n)
            return -1;
        int low = 0, high = n - 1, mid;
        while(low <= high) {
            mid = (low + high) >> 1;
            if(A[mid] == target)
                return mid;
            if(A[low] < A[mid] && target < A[mid] && target >= A[low]) {
                high = mid - 1;
            } else if(A[low] > A[mid] && !(target > A[mid] && target <= A[high])) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }
};
