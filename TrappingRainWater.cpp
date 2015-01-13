class Solution {
public:
    int trap(int A[], int n) {
        if(n == 0)
            return 0;
        vector<int> left_max(n, 0);
        vector<int> right_max(n, 0);
        for(int i = 1; i < n; i++)
            left_max[i] = max(left_max[i - 1], A[i - 1]);
        for(int i = n - 2; i >= 0; i--)
            right_max[i] = max(right_max[i + 1], A[i + 1]);
        int ret = 0;
        for(int i = 0; i < n; i++) {
            int h = min(right_max[i], left_max[i]);
            if(h > A[i])
                ret += h - A[i];
        }
        return ret;
    }
};
