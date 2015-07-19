class Solution {
public:
    double myPow(double x, int n) {
       return calc_pow(x, n) ;
    }
private:
    double calc_pow(double x, long long n) {
        if (n == 0) {
            return 1;
        }
        if (n < 0) {
            return 1 / calc_pow(x, -n);
        }
        double mid_res = calc_pow(x, n / 2);
        if (n % 2 == 0) {
            return mid_res * mid_res;
        } else {
            return mid_res * mid_res * x;
        }
    }
};
