class Solution {
public:
    int climbStairs(int n) {
        if(n == 0 || n == 1)
            return 1;
        int i, prev = 1, pprev = 1, cur;
        for(i = 2; i <= n; i++) {
            cur = prev + pprev;
            pprev = prev;
            prev = cur;
        }
        return cur;
    }
};
