class Solution {
public:
    int trap(int A[], int n) {
        int *right_max = new int[n]();
        int *left_max = new int[n]();
        
        int i;
        for(i = 1; i < n; i++) {
            right_max[n - 1 - i] = max(right_max[n - i], A[n - i]);
            left_max[i] = max(left_max[i - 1], A[i - 1]);
        }
        int sum = 0;
        for(i = 0; i < n; i++) {
            int m = min(right_max[i], left_max[i]);
            if(m > A[i])
                sum += m - A[i];
        }
        delete[] right_max;
        delete[] left_max;
        return sum;
    }
};
