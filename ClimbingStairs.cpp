class Solution {
public:
    int climbStairs(int n) {
        if (n == 1 || n == 2) {
            return n;
        }
        int prev = 2;
        int pprev = 1;
        int cur;
        for (int i = 3; i <= n; i++) {
            cur = prev + pprev;
            pprev = prev;
            prev = cur;
        }
        return cur;
    }
};
