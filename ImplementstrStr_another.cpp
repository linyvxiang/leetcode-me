class Solution {
public:
    void calc_next(char *pattern, int next[])
    {
        int p = -1, q, m = strlen(pattern);
        next[0] = -1;
        for(q = 1; q < m; q++) {
            while(p > -1 && pattern[p + 1] != pattern[q])
                p = next[p];
            if(pattern[p + 1] == pattern[q])
                p = p + 1;
            next[q] = p;
        }
    }
    int kmp(char *text, char*pattern, int next[])
    {
        int m = strlen(text), n = strlen(pattern);
        int p = -1, q;
        for(q = 0; q < m; q++) {
            while(p > -1 && pattern[p + 1] != text[q])
                p = next[p];
            if(pattern[p + 1] == text[q])
                p = p + 1;
            if(p == n - 1)
                return q - p;
        }
        return -1;
    }
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int next[strlen(needle)], m = strlen(haystack), n = strlen(needle);
        if(!n)
            return haystack;
        if(!haystack || m < n)
            return NULL;
        calc_next(needle, next);
        int pos = kmp(haystack, needle, next);
        if(pos != -1)
            return haystack + pos;
        return NULL;
    }
};
