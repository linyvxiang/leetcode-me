class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        if(!k)
            return res;
        int cur_len;
        vector<char> numbers;
        for(cur_len = 0; cur_len <= n; cur_len++)
            numbers.push_back('1' + cur_len);
        cur_len = n;
        k--;
        while(cur_len--) {
            int pos = k / fac(cur_len);
            res += numbers[pos];
            numbers.erase(numbers.begin() + pos);
            k %= fac(cur_len);
        }
        return res;
    }
private:
    int fac(int n)
    {
        if(n == 0 || n == 1)
            return 1;
        return n * fac(n - 1);
    }
};
