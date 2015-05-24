class Solution {
public:
    int divide(int dividend, int divisor) {
        long long ret = do_divide((long long)dividend, (long long)(divisor));
        if (ret < INT_MIN || ret > INT_MAX) {
            ret = INT_MAX;
        }
        return (int)ret;
    }
private:
    long long do_divide(long long dividend, long long divisor) {
        long long ret = 0;
        if (divisor < 0 && dividend < 0) {
            return do_divide(-dividend, -divisor);
        } else if (dividend < 0) {
            return -1 * do_divide(-dividend, divisor);
        } else if (divisor < 0) {
            return -1 * do_divide(dividend, -divisor);
        }
        if (divisor == 1) {
            return dividend;
        }
        while (dividend >= divisor) {
            int order = 0;
            for (; dividend >= (divisor << order); order++ ) {
                dividend -= (divisor << order);
                ret += 1 << order;
            }
        }
        return ret;
    }
};
