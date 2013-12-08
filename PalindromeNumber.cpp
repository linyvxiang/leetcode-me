class Solution {
public:
    bool isPalindrome(int x) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int pre = 0, now = 0;
        if(x < 0)
            return false;
        while(pow(10, now) <= x) {
            pre = now;
            now++;
        }
        int cur = 0;
        while( cur <= pre / 2) {
            if((x / (int)pow(10, cur)) % 10 != (x / (int)pow(10, pre - cur)) % 10)
                return false;
            cur++;
        }
        return true;
    }
};
