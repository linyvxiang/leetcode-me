class Solution {
public:
    bool search(int A[], int n, int target) {
        if(!n)
            return false;
        int low = 0, high = n - 1, mid;
        while(low <= high) {
            mid = (low + high) >> 1;
            if(A[mid] == target)
                return true;
            if(A[low] < A[mid]) {
                if(target >= A[low] && target < A[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            } else if(A[low] > A[mid]) {
                if(target > A[mid] && target < A[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            } else {
                if(low + 1 < n && A[low] < A[low + 1])
                    high = mid - 1;
                else
                    return low = mid + 1;
            }
        }
        return false;
    }
};
