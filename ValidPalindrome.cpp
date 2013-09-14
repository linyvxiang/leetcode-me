class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string format;
        if(!s.size()) {
            return true;
        }
        int i,j=0;
        for(i = 0;i < s.size(); i++) {
            if(s[i]>='a' && s[i]<='z') {
                format += s[i];
            } else if(s[i]>='A' && s[i] <= 'Z') {
                format += s[i] - 'A' + 'a';
            } else if(s[i] >= '0' && s[i] <= '9') {
                format += s[i];
            } 
        }
        if(!format.size())
            return true;
        int begin=0,end=format.size()-1;
        while(begin < end) {
            if(format[begin] == format[end]) {
                begin++;
                end--;
            } else {
                return false;
            }
        }
        return true;
    }
};
