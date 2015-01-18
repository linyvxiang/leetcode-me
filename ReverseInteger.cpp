class Solution {
public:
    int reverse(int x) {
        int flag = x >= 0 ? 1 : -1;
        x = x >= 0 ? x : -x;
        long long r = 0;
        while(x) {
            r = r * 10 + x % 10;
            x /= 10;
        }
        return r * flag * ((INT_MIN <= r && r <= INT_MAX) ? 1 : 0);
    }
};
