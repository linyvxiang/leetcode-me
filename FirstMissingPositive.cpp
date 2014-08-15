class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int i;
        for(i = 0; i < n; ) {
            if(A[i] == i)
                i++;
            else if(0 <= A[i] && A[i] < n && A[A[i]] != A[i])
                swap(A[i], A[A[i]]);
            else 
                i++;
        }
        for(i = 1; i < n; i++)
            if(A[i] != i)
                return i;
        return A[0] == n ? n + 1 : n;
    }
};
