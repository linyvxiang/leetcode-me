class Solution {
public:
    double pow(double x, int n) {
        if(n < 0)
            return 1.0 / power(x, -n);
        return power(x, n);
    }
private:
    double power(double x, int n)
    {
        if(n == 0)
            return 1;
        double mid = power(x, n / 2);
        if(n % 2 == 0)
            return mid * mid;
        return mid * mid * x;
    }
};
