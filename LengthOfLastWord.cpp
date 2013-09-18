ss Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!s)
            return 0;
        int start = 0,end = strlen(s) - 1;
        while(s[end] == ' ' && end >= 0)
            end--;
        if(end < 0)
            return 0;
        start = end;
        while(s[start] != ' ' && start >= 0)
            start--;
        return end - start;
        
    }
};
