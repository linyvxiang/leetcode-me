class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') {
            return 0;
        }
        int prev = 0;
        int cur = 1;
        for (int i = 1; i <= s.size(); i++) {
            if (s[i - 1] == '0') {
                cur = 0;
            }
            if (i < 2 || !(s[i - 2] == '1' || s[i - 2] == '2' && s[i - 1] <= '6')) {
                prev = 0;
            }
            int tmp = cur;
            cur = cur + prev;
            prev = tmp;
        }
        return cur;
    }
};
