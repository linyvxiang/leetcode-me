class Solution {
public:
    int longestValidParentheses(string s) {
        int i, last = -1;
        stack<int> lefts;
        int max_len = 0;
        for(i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                lefts.push(i);
            } else {
                if(lefts.empty())
                    last = i;
                else {
                    lefts.pop();
                    if(lefts.empty()) {
                        max_len = max(max_len, i - last);
                    } else {
                        max_len = max(max_len, i - lefts.top());
                    }
                }
            }
        }
        return max_len;
    }
};
