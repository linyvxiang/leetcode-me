class Solution {
public:
    int longestValidParentheses(string s) {
        bool matched[s.size()];
        int pos;
        memset(matched, false, sizeof(matched));
            
        stack<int> S;
        for(pos = 0; pos < s.size(); pos++) {
            if(s[pos] == '(') {
                S.push(pos);
            } else {
                if(!S.empty()) {
                    matched[S.top()] = true;
                    matched[pos] = true;
                    S.pop();
                }
            }
        }

        int max_len = 0, cur_len = 0;
        for(pos = 0; pos < s.size(); pos++) {
            if(matched[pos])
                cur_len++;
            else
                cur_len = 0;
            max_len = max(max_len, cur_len);
        }
        return max_len;
    }
};
