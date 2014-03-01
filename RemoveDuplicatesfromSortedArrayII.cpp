class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n == 0)
            return 0;
        int back = 0, front = 1, count = 1;
        for(; front < n; front++) {
            if(A[back] == A[front]) {
                if(count < 2) {
                    A[++back] = A[front];
                    count++;
                }
            } else {
                A[++back] = A[front];
                count = 1;
            }
        }
        return back + 1;
    }
};
