class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.empty()) {
            return 0;
        }
        vector<bool> matched(s.size(), false);
        stack<int> S;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                S.push(i);
            } else {
                if (!S.empty()) {
                    matched[S.top()] = true;
                    S.pop();
                    matched[i] = true;
                }
            }
        }
        int max_len = 0;
        int cur_len = 0;
        for (int i = 0; i < s.size(); i++) {
            if (matched[i] == false) {
                cur_len = 0;
            }  else {
                cur_len++;
                max_len = max(max_len, cur_len);
            }
        }
        max_len = max(max_len, cur_len);
        return max_len;
    }
};
