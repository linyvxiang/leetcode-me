class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a = dividend;
        long long b = divisor;
        long long ret = do_divide(a, b);
        if (ret > INT_MAX || ret < INT_MIN) {
            return INT_MAX;
        }
    }
private:
    long long do_divide(long long dividend, long long divisor) {
        if (dividend > 0 && divisor < 0) {
            return -1 * do_divide(dividend, -divisor);
        } else if (dividend < 0 && divisor > 0) {
            return -1 * do_divide(-dividend, divisor);
        } else if (dividend < 0 && divisor < 0) {
            return do_divide(-dividend, -divisor);
        }
        long long result = 0;
        while (dividend >=divisor) {
            for (long long pow = 0; (divisor << pow) <= dividend; pow++) {
                dividend -= (divisor << pow);
                result += (1 << pow);
            }
        }
        return result;   
    }
};
