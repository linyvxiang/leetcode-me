class Solution {
public:
    int find_small_index(int A[], int n)
    {
        int i = 1;
        for(; i <n; i++) {
            if(A[i] < A[0])
                return i;
        }
        return -1;
    }
    int binary_search(int A[], int start, int end, int target)
    {
        while(start <= end) {
            int mid = (start + end) >> 1;
            if(A[mid] == target)
                return mid;
            if(A[mid] > target) {
                end = mid - 1;
            } else
                start = mid + 1;
        }
        return -1;
    }
    int search(int A[], int n, int target) {
        if(n == 0)
            return -1;
        int pos = find_small_index(A, n);
        if(pos != -1) {//OK, some one after A[0] is smaller, so the first part is bigger than the second part
            if(A[0] <= target && target <= A[pos - 1]) {//maybe in the first part, couldn't in the second part
                return binary_search(A, 0, pos - 1, target);
            } else if(A[pos] <= target && target <= A[n - 1]) {// maybe in the second part
                return binary_search(A, pos, n - 1, target);
            } else
                return -1;
        } else { // A[0] is the smallest
            return binary_search(A, 0, n - 1, target);
        }
    }
};
