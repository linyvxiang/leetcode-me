class Solution {
public:
    int maxSubArray(int A[], int n) {
        if(!n)
            return 0;
        int res[n], i;
        res[0] = A[0];
        int max_sum = A[0];
        for(i = 1; i < n; i++) {
            if(res[i - 1] > 0)
                res[i] = res[i - 1] + A[i];
            else
                res[i] = A[i];
            max_sum = max(max_sum, res[i]);
        }
        return max_sum;
    }
};
