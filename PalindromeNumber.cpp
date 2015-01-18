class Solution {
    public:
        bool isPalindrome(int x) {
            int t = x, r = 0;
            while(x) {
                r = r * 10 + x % 10;
                x /= 10;
            }
            return t == r && t >= 0;
        }
};
