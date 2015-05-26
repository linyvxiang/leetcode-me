class Solution {
public:
    int reverse(int x) {
        return do_reverse((long long)x);
    }
private:
    int do_reverse(long long x) {
        if (x < 0) {
            return -1 * do_reverse(-x);
        }
        long long ret = 0;
        while (x) {
            ret = ret * 10 + x % 10;
            x /= 10;
        }
        if (ret > INT_MAX || ret < INT_MIN) {
            ret = 0;
        }
        return (int)ret;
    }
};
