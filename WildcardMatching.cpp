class Solution {
public:
    bool isMatch(string s, string p) {
        int s_pos = 0;
        int p_pos = 0;
        int pre_s = 0;
        int pre_p = 0;
        bool star = false;
        for (; s_pos < s.size(); s_pos++, p_pos++) {
            switch (p[p_pos]) {
                case '?' :
                    break;
                case '*' :
                    while (p_pos < p.size() && p[p_pos] == '*') {
                        p_pos++;
                    }
                    if (p_pos == p.size()) {
                        return true;
                    }
                    pre_p = p_pos;
                    pre_s = s_pos;
                    s_pos--;
                    p_pos = pre_p - 1;
                    star = true;
                    break;
                default:
                    if (s[s_pos] != p[p_pos]) {
                        if (!star) {
                            return false;
                        }
                        pre_s++;
                        s_pos = pre_s - 1;
                        p_pos = pre_p - 1;
                    }
            }
        }
        while (p_pos < p.size() && p[p_pos] == '*') {
            p_pos++;
        }
        return p_pos == p.size();
    }
};
