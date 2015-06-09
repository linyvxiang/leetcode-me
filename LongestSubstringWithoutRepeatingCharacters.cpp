class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        int last_index = 0;
        int cur_pos = 0;
        int count[260];
        memset(count, -1, 260 * sizeof(int));
        while (cur_pos < s.size()) {
            if (count[s[cur_pos]] >= 0) {
                max_len = max(max_len, cur_pos - last_index);
                last_index = count[s[cur_pos]] + 1;
                cur_pos = last_index;
                memset(count, -1, 260 * sizeof(int));
            } else {
                count[s[cur_pos]] = cur_pos;
                cur_pos++;
            }
        }
        return max(max_len, cur_pos - last_index);
    }
};
