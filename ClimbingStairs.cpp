class Solution {
    public:
        int climbStairs(int n) {
            if(n == 1 || n == 2)
                return n;
            int cur = 3, ret = 0, prev = 2, pprev = 1;
            for(; cur <= n; cur++) {
                ret = prev + pprev;
                pprev = prev;
                prev = ret;
            }
            return ret;
        }
};
