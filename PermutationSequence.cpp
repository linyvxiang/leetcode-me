class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers;
        for (int i = 1; i <= n; i++) {
            numbers.push_back(i);
        }
        return generate_permutation(numbers, k - 1);
    }
private:
    int fact(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        return fact(n - 1) * n;
    }
    string generate_permutation(vector<int>& numbers, int k) {
        string ret;
        while (numbers.size()) {
            int f = fact(numbers.size() - 1);
            int pos = k / f;
            k %= f;
            ret += numbers[pos] + '0';
            numbers.erase(numbers.begin() + pos);
        }
        return ret;
    }
};
