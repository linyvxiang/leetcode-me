class Solution {
public:
    bool isPalindrome(int x) {
        long long orig = x;
        long long ret = 0;
        while (x) {
            ret = ret * 10 + x % 10;
            x /= 10;
        }
        return orig == ret && orig >= 0;
    }
};
