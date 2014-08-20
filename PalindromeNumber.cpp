class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        int n_x = x;
        int r_x = 0;
        while(x) {
            r_x = r_x * 10 + x % 10;
            x /= 10;
        }
        return r_x == n_x;
    }
};
