class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0 || s[0] == '0')
            return 0;
        int cur_pos = 0;
        int len = s.size();
        int num_prev = 1, num_p_prev = 1, num_cur = 1;
        for(; cur_pos < len; cur_pos++) {
            if(s[cur_pos] == '0') {
                if(cur_pos - 1 >= 0 && check(cur_pos, s)) {
                    num_cur = num_p_prev;
                    num_prev = num_cur;
                    num_p_prev = 0;
                } else {
                    num_cur = 0;
                    break;
                }
            } else if(s[cur_pos] != '0' && cur_pos - 1 >= 0 &&
                        check(cur_pos, s)) {
                num_cur = num_prev + num_p_prev;
                num_p_prev = num_prev;
                num_prev = num_cur;
            } else if(s[cur_pos] != '0' && cur_pos - 1 >= 0 &&
                        !check(cur_pos, s)) {
                num_cur = num_prev;
                num_p_prev = num_prev;
            }
        }
        return num_cur;
    }
private:
    bool check(int pos, string &s)
    {
        int res = 0;
        res = (s[pos - 1] - '0') * 10 + s[pos] -'0';
        return res <= 26;
    }
};
