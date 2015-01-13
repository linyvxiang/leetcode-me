class Solution {
    public:
        double pow(double x, int n) {
            return do_pow(x, n);
        }
    private:
        double do_pow(double x, long long n)
        {
            if(n < 0)
                return 1 / do_pow(x, -n);
            if(n == 0)
                return 1;
            if(x == 1 || n == 1)
                return x;
            double m = do_pow(x, n / 2);
            if(n % 2 == 0)
                return m * m;
            else
                return m * m * x;
        }
};
