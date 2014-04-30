class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = strlen(s);
        int end = len - 1;
        while(end >= 0) {
            if(s[end] != ' ')
                break;
            end--;
        }
        if(end < 0)
            return 0;
        int start = end;
        while(start >= 0 && s[start] != ' ')
            start--;
        if(start < 0)
            return end + 1;
        return end - start;
    }
};
