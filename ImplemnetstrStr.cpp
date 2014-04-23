class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int src_len = strlen(haystack);
        int dst_len = strlen(needle);
        if(!dst_len)
            return haystack;
        if(!haystack || src_len < dst_len)
            return  NULL;
        int i;
        for(i = 0; i <= src_len - dst_len; i++)
            if(strncmp(haystack + i, needle, dst_len) == 0)
                return haystack + i;
        return NULL;
    }
};
