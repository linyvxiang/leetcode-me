class Solution {
public:
    int maxSubArray(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int res[n];
        res[0] = A[0];
        if(n == 0)
            return A[0];
        int i, max_sum = A[0];
        for(i = 1; i < n; i++) {
            if(res[i -1] >= 0)
                res[i] = res[i - 1] + A[i];
            else
                res[i] = A[i];
            if(res[i] > max_sum)
                max_sum = res[i];
        }
        return max_sum;
    }
};
