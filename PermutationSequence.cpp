class Solution {
public:
    string getPermutation(int n, int k) {
        vector<char> numbers;
        for (int i = 0; i < n; i++) {
            numbers.push_back(i + '1');
        }
        k--;
        string ret;
        while (--n) {
            int fac = fact(n);
            int cur_pos = k / fac;
            k %= fac;
            ret += numbers[cur_pos];
            numbers.erase(numbers.begin() + cur_pos);
        }
        ret += numbers[0];
        return ret;
    }
private:
    int fact(int n) {
        if (n == 0 || n == 1) {
            return n;
        }
        return n * fact(n - 1);
    }
};
