class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0 || x == 1) {
            return 1;
        }
        if (x == -1) {
            return n % 2 == 0 ? 1 : -1;
        }
        if (n == 1) {
            return x;
        }
        if (n < 0) {
            return 1.0 / myPow(x, -n);
        }
        double mid = myPow(x, n / 2);
        if (n % 2 == 1) {
            return mid * mid * x;
        } else {
            return mid * mid;
        }
    }
};
