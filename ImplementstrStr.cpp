class Solution {
public:
    int strStr(char *haystack, char *needle) {
        int len_s = strlen(haystack), len_p = strlen(needle);
        if(len_s < len_p)
            return -1;
        for(int cur_pos = 0; cur_pos <= len_s - len_p; cur_pos++) {
            bool flag = true;
            for(int p = 0; p < len_p; p++) {
                if(needle[p] != haystack[p + cur_pos]) {
                    flag =false;
                    break;
                }
            }
            if(flag)
                return cur_pos;
        }
        return -1;
    }
};
