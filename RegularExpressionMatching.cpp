class Solution {
public:
    bool isMatch(string s, string p) {
        return check_is_match(s, 0, p, 0);
    }
private:
    bool check_is_match(const string& s, int s_pos, const string& p, int p_pos) {
        if (s_pos < s.size() && p_pos == p.size()) {
            return false;
        }
        if (s_pos == s.size() && p_pos == p.size()) {
            return true;
        }

        if (s[s_pos] == p[p_pos] || p[p_pos] == '.') {
            if (p_pos + 1 < p.size() && p[p_pos + 1] == '*') {
                int pos = s_pos;
                while (pos < s.size() && (s[pos] == p[p_pos] || p[p_pos] == '.')) {
                    bool ret = check_is_match(s, pos + 1, p, p_pos + 2);
                    if (ret) {
                        return true;
                    }
                    pos++;
                }
                return check_is_match(s, s_pos, p, p_pos + 2);
            } else {
                return check_is_match(s, s_pos + 1, p, p_pos + 1);
            }
        } else if (p_pos + 1 < p.size() && p[p_pos + 1] == '*') {
            return check_is_match(s, s_pos, p, p_pos + 2);
        } else {
            return false;
        }
    }
};
