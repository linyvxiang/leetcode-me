class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int low = 0, high = n -1;
        int mid, cur_num;
        while(low <= high && low < n && high >= 0) {
            mid = (low + high) >> 1;
            cur_num = A[mid];
            if(cur_num == target)
                return mid;
            if(cur_num < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        if(A[mid] < target)
            return low;
        else
            return high + 1;
    }
};
