class Solution {
public:
    void reverseWords(string &s) {
        int start = 0;
        int end = 0;
        string ret;
        while (start < s.size() && s[start] == ' ') {
            start++;
        }
        if (start == s.size()) {
            s = "";
            return;
        }
        while (start < s.size()) {
            end = start;
            while (end < s.size() && s[end] != ' ') {
                end++;
            }
            string tmp(s.begin() + start, s.begin() + end);
            reverse(tmp.begin(), tmp.end());
            tmp += ' ';
            ret += tmp;
            while (end < s.size() && s[end] == ' ') {
                end++;
            }
            start = end;
        }
        ret.resize(ret.size() - 1);
        reverse(ret.begin(), ret.end());
        s = ret;
    }
};
