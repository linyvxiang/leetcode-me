class Solution {
public:
    void sortColors(int A[], int n) {
        int slow = -1, fast = n, mid = 0;
        while(mid < n) {
            if(A[mid] == 0 && mid > slow) {
                A[mid] = A[slow + 1];
                A[slow + 1] = 0;
                slow++;
            } else if(A[mid] == 2 && mid < fast) {
                A[mid] = A[fast - 1];
                A[fast - 1] = 2;
                fast--;
            } else {
                mid++;
            }
        }
    }
};
