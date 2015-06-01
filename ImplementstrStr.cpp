class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size()) {
            return -1;
        }
        for (int cur_pos = 0; cur_pos <= haystack.size() - needle.size(); cur_pos++) {
            bool matched = true;
            for (int i = 0; i < needle.size(); i++) {
                if (haystack[cur_pos + i] != needle[i]) {
                    matched = false;
                    break;
                }
            }
            if (matched) {
                return cur_pos;
            }
        }
        return -1;
    }
};