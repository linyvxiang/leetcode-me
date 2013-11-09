class Solution {
public:
    int climbStairs(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(n == 0 || n == 1)
            return 1;
        if(n == 2) 
            return 2;
        int res_n_1 = 2, res_n_2 = 1;
        int res_n = 3;
        int cur_level = 3;
        for(; cur_level <= n; cur_level++) {
            res_n = res_n_1 + res_n_2;
            res_n_2 = res_n_1;
            res_n_1 = res_n;
        }
        return res_n;
    }
};
