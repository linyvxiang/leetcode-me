class Solution {
public:
    int find_kth(int A[], int m, int B[], int n, int kth)
    {
        if(m > n)
            return find_kth(B, n, A, m, kth);
        if(m == 0)
            return B[kth - 1];
        if(kth == 1)
            return min(A[0], B[0]);
        
        int pa = min(kth / 2, m), pb = kth - pa;
        if(A[pa - 1] < B[pb - 1])
            return  find_kth(A + pa, m - pa, B, n, kth - pa);
        else if(A[pa - 1] > B[pb - 1])
            return find_kth(A, m, B + pb, n - pb, kth - pb);
        else
            return A[pa - 1];
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int N = (m + n);
        if(N & 0x1)// odd
            return find_kth(A, m, B, n, N / 2 + 1);
        else
            return (find_kth(A, m, B, n, N / 2) + find_kth(A, m, B, n, N / 2 + 1)) * 0.5;
    }
};
