class Solution {
    public:
        int numDecodings(string s) {
            if(s.empty() || s[0] == '0')
                return 0;
            int prev = 1, pprev = 1;
            int cur_sum = 1, cur_pos;
            for(cur_pos = 1; cur_pos < s.size(); cur_pos++) {
                if(s[cur_pos] != '0' && (s[cur_pos - 1] == '1'
                            || (s[cur_pos - 1] == '2' && 
                                '0' <= s[cur_pos] && 
                                s[cur_pos] <= '6'))) {
                    cur_sum = prev + pprev;
                    pprev = prev;
                } else if(s[cur_pos - 1] == '0' ||
                        s[cur_pos - 1] > '2' ||
                        (s[cur_pos - 1] == '2' && 
                         s[cur_pos] > '6')) {
                    if(s[cur_pos] == '0')
                        prev = 0;
                    cur_sum = prev;
                    pprev = prev;
                } else if(s[cur_pos] == '0') {
                    if(s[cur_pos - 1] == '0' ||
                            s[cur_pos - 1] > '2')
                        pprev = 0;
                    cur_sum = pprev;
                    pprev = 0;
                }
                prev = cur_sum;
            }
            return cur_sum;
        }
};
