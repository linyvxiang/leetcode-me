class Solution {
public:
    int divide(int dividend, int divisor) {
        long long ret = 0;
        int flag = 1;
        if((dividend > 0 && divisor < 0) || 
                (dividend < 0 && divisor > 0))
            flag = -1;
        long long m = (long long)dividend;
        long long n = (long long)divisor;
        m = m > 0 ? m : -m;
        n = n > 0 ? n : -n;
        while(m >= n) {
            for(int i = 0; m >= n << i; i++) {
                ret += 1 << i;
                m -= n << i;
            }
        }
        ret *= flag;
        if(ret > INT_MAX || ret < INT_MIN)
            return INT_MAX;
        return ret;
    }
};
