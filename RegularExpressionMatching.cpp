class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int len_s = strlen(s), len_p = strlen(p);
        return do_judge(s, 0, len_s, p, 0, len_p);
    }
private:
    bool do_judge(const char *s, int pos_s, int len_s,
                    const char *p, int pos_p, int len_p)
    {
        if((pos_s < len_s && pos_p >= len_p))
            return false;
        if(pos_s == len_s && pos_p == len_p)
            return true;
        if(s[pos_s] == p[pos_p] || p[pos_p] == '.') {
            if(pos_p + 1 < len_p && p[pos_p + 1] == '*') {
                int pos = pos_s;
                while(pos < len_s && (s[pos] == p[pos_p] || p[pos_p] == '.')) {
                    if(do_judge(s, pos + 1, len_s, p, pos_p + 2, len_p))
                        return true;
                    pos++;
                }
                return do_judge(s, pos_s, len_s, p, pos_p + 2, len_p);
            } else {
                return do_judge(s, pos_s + 1, len_s, p, pos_p + 1, len_p);
            }
        } else if(pos_p + 1 < len_p) {
            if(p[pos_p + 1] == '*')
                return do_judge(s, pos_s, len_s, p, pos_p + 2, len_p);
            return false;
        } else {
            return false;
        }
    }
};
