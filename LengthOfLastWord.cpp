class Solution {
    public:
        int lengthOfLastWord(const char *s) {
            int cur_pos = strlen(s) - 1;
            while(cur_pos >= 0 && s[cur_pos] == ' ')
                cur_pos--;
            int end = cur_pos;
            while(cur_pos >= 0 && s[cur_pos] != ' ')
                cur_pos--;
            return  end - cur_pos;
        }
};
