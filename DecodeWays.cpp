class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) {
            return 0;
        }
        if (s[0] == '0') {
            return 0;
        }
        int prev = 1;
        int pprev = 0;
        int cur_steps = 1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i - 1] == '0') {
                if (s[i] == '0') {
                    cur_steps = 0;
                    prev = 0;
                    pprev = 0;
                } else {
                    cur_steps = prev;
                    pprev = prev;
                    prev = cur_steps;
                }
            } else if (s[i - 1] == '1') {
                if (s[i] == '0') {
                    cur_steps = pprev;
                    pprev = 0;
                    prev = cur_steps;
                } else {
                    cur_steps = pprev + prev;
                    pprev = prev;
                    prev = cur_steps;
                }
            } else if (s[i - 1] == '2') {
                if (s[i] == '0') {
                    cur_steps = pprev;
                    pprev = 0;
                    prev = cur_steps;
                } else if (s[i] >= '1' && s[i] <= '6') {
                    cur_steps = prev + pprev;
                    pprev = prev;
                    prev = cur_steps;
                } else {
                    cur_steps = prev;
                    pprev = prev;
                    prev = cur_steps;
                }
            } else {
                if (s[i] == '0') {
                    cur_steps = 0;
                    prev = 0;
                    pprev = 0;
                } else {
                    cur_steps = prev;
                    pprev = prev;
                    prev = cur_steps;
                }
            }
        }
        return cur_steps;
    }
};
