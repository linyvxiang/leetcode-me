class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int len = s.size();
        bool match[len + 1] = {false};
        match[0] = true;
        for (int i = 1; i <= len; i++) {
            for (int j = i - 1; j >= 0; j--) {
                string cur_word(s, j, i - j);
                if (match[j] && wordDict.find(cur_word) != wordDict.end()) {
                    match[i] = true;
                    break;
                }
            }
        }
        return match[len];
    }
};
