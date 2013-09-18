class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

       int len_dst = strlen(haystack);
       int len_src = strlen(needle); 
       if(!len_src)
        return haystack;
       if(len_dst < len_src || !haystack)
        return NULL;
       int i;
       for(i = 0; i <= len_dst - len_src; i++) {
           if(memcmp(haystack + i,needle,len_src) == 0) {
               return haystack + i;
           }
       }
       return NULL;
    }
};
