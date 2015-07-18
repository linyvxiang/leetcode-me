class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if (s.empty()) {
            return false;
        }
        bool check[s.size() + 1] = { false };
        check[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (check[j]) {
                    string tmp(s.begin() + j, s.begin() + i);
                    if (wordDict.find(tmp) != wordDict.end()) {
                        check[i] = true;
                        break;
                    }
                }
            }
        }
        return check[s.size()];
    }
};
