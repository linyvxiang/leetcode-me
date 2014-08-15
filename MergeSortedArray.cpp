class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int fin_pos = m + n - 1;
        int pos_a = m - 1, pos_b = n - 1;
        while(pos_a >= 0 && pos_b >= 0)
            A[fin_pos--] = A[pos_a] > B[pos_b] ? A[pos_a--] : B[pos_b--];
        while(pos_b >= 0)
                A[fin_pos--] = B[pos_b--];
    }
};
