class Solution {
public:
    double pow(double x, int n) {
        if(n == 0 || x == 1)
            return 1;
        if(x == -1)
            return n % 2 == 0 ? 1 : -1;
        if(n < 0)
            return 1.0 / pow(x, -n);
        double mid = pow(x, n >> 1);
        if(n & 0x1)
            return mid * mid * x;
        return mid * mid;
    }
};
