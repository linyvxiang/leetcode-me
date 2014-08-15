class Solution {
public:
    void sortColors(int A[], int n) {
        int slow = -1, fast = n, cur = 0;
        while(cur < n) {
            if(A[cur] == 0 && slow < cur) {
                swap(A[cur], A[slow + 1]);
                slow++;
            } else if(A[cur] == 2 && cur < fast) {
                swap(A[cur], A[fast - 1]);
                fast--;
            } else {
                cur++;
            }
        }
    }
};
