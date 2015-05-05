class Solution {
    public:
        void reverseWords(string &s) {
            string::iterator sit = s.begin();
            string::iterator eit;
            string res;
            while (sit != s.end()) {
                while (sit != s.end() && *sit == ' ') {
                    sit++;
                }
                if (sit == s.end()) {
                    break;
                }
                eit = sit;
                while (eit != s.end() && *eit != ' ') {
                    eit++;
                }
                reverse(sit, eit);
                if (!res.empty()) {
                    res += ' ';
                }
                res += string(sit, eit);
                sit = eit;
            }
            reverse(res.begin(), res.end());
            s = res;
        }
};
