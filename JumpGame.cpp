class Solution {
public:
    bool canJump(int A[], int n) {
        int i;
        int step = A[0];
        if(n == 1)
            return true;
        
        for(i = 0; i < n; i++) {
            if(step > 0) {
                step--;
                step = max(step, A[i]);
            } else {
                return false;
            }
        }
        return  true;
    }
};
