class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> left_pos;
        int last = -1, pos, max_len = 0;
        for(pos = 0; pos < s.size(); pos++) {
            if(s[pos] == '(') {
                left_pos.push(pos);
            } else {
                if(left_pos.empty()) {
                    last = pos;
                } else {
                    left_pos.pop();
                    if(left_pos.empty())
                        max_len = max(max_len, pos - last);
                    else 
                        max_len = max(max_len, pos - left_pos.top());
                }
            }
        }
        return max_len;
    }
};
