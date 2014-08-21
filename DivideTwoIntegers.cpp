class Solution {
public:
    int divide(int dividend, int divisor) {
        long long  a = dividend, b = divisor;
        int flag = 1;
        if(a < 0 && b > 0 || a > 0 && b < 0)
            flag = -1;
        a = abs(a);
        b = abs(b);
        int i, res = 0;
        while(a >= b) {
            for(i = 0; a >= (b << i); i++) {
                a -= b << i;
                res += 1 << i;
            }
        }
        return res * flag;
    }
};
