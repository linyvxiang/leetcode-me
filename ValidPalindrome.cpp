class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0, end = s.size() - 1;
        while(start <= end) {
            while(start < s.size() && !is_alapha(s, start))
                start++;
            if(start >= end)
                return true;
            while(end >= 0 && !is_alapha(s, end))
                end--;
            if(end <= start)
                return true;
            if(!check(s, start, end))
                return false;
            start++;
            end--;
        }
        return true;
    }
private:
    bool is_alapha(string &s, int pos)
    {
        return 'a' <= s[pos] && s[pos] <= 'z' ||
                'A' <= s[pos] && s[pos] <= 'Z' ||
                '0' <= s[pos] && s[pos] <= '9';
    }
    bool check(string &s, int pos_a, int pos_b)
    {
        char ch_a = s[pos_a], ch_b = s[pos_b];
        if('a' <= s[pos_a] && s[pos_a] <= 'z')
            ch_a = ch_a - 'a' + 'A';
        if('a' <= s[pos_b] && s[pos_b] <= 'z')
            ch_b = ch_b - 'a' + 'A';
        return ch_a == ch_b;
    }
};
