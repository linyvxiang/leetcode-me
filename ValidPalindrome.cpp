class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;
        while (start <= end) {
            if (!check_alpha_num(s[start])) {
                start++;
                continue;
            }
            if (!check_alpha_num(s[end])) {
                end--;
                continue;
            }
            if (!check_same(s[start], s[end])) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
private:
    bool check_alpha_num(char ch) {
        return 'a' <= ch && ch <= 'z'
                || 'A' <= ch && ch <= 'Z'
                    || '0' <= ch && ch <= '9';
    }
    bool check_same(char ch1, char ch2) {
        char a = ch1;
        char b = ch2;
        if ('A' <= ch1 && ch1 <= 'Z') {
            a = ch1 - 'A' + 'a';
        }
        if ('A' <= ch2 && ch2 <= 'Z') {
            b = ch2 - 'A' + 'a';
        }
        return a == b;
    }
};
