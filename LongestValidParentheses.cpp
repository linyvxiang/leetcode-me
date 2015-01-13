class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> left_pos;
        vector<bool> valid(s.size(), false);
        int cur_pos = 0;
        while(cur_pos < s.size()) {
            if(s[cur_pos] == '(') {
                left_pos.push(cur_pos);
            } else {
                if(!left_pos.empty()) {
                    valid[cur_pos] = true;
                    valid[left_pos.top()] = true;
                    left_pos.pop();
                }
            }
            cur_pos++;
        }
        int max_len = 0;
        int next_pos = 0;
        cur_pos = 0;
        while(cur_pos < s.size()) {
            if(!valid[cur_pos]) {
                cur_pos++;
                continue;
            } else {
                next_pos = cur_pos;
                while(cur_pos < s.size() && valid[next_pos])
                    next_pos++;
                if(max_len < next_pos - cur_pos)
                    max_len = next_pos - cur_pos;
                cur_pos = next_pos;
            }
        }
        return max_len;
    }
};
