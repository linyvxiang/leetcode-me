class Solution {
public:
    int longestValidParentheses(string s) {
        vector<bool> matched(s.size(), false);
        stack<int> pos_stack;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                pos_stack.push(i);
            } else if (s[i] == ')') {
                if (!pos_stack.empty()) {
                    matched[pos_stack.top()] = true;
                    matched[i] = true;
                    pos_stack.pop();
                }
            }
        }
        int cur_len = 0;
        int max_len = 0;
        for (int i = 0; i < s.size(); i++) {
            if (!matched[i]) {
                cur_len = 0;
            } else {
                cur_len++;
                max_len = max(max_len, cur_len);
            }
        }
        return max_len;
    }
};
