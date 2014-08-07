class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if((m + n) & 0x1) { // odd
            return do_find_mid(A, m, B, n, (m + n) / 2 + 1);
        } else {
            return (do_find_mid(A, m, B, n, (m + n) / 2) +
                    do_find_mid(A, m, B, n, (m + n) / 2 + 1)) / 2.0;
        }
    }
private:
    int do_find_mid(int A[], int m, int B[], int n, int k)
    {
        if(m > n)
            return do_find_mid(B, n, A, m, k);
        if(m == 0)
            return B[k - 1];
        if(k == 1)
            return min(A[0], B[0]);

        int m1 = min(m, k / 2), m2 = k - m1;
        if(A[m1 - 1] == B[m2 - 1]) {
            return A[m1 - 1];
        } else if(A[m1 - 1] < B[m2 - 1]) {
            return do_find_mid(A + m1, m - m1, B, n, k - m1);
        } else {
            return do_find_mid(A, m, B + m2, n - m2, k - m2);
        }
    }
};
