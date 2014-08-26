class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> res(s.size() + 1, false);
        int i, j;
        res[0] = true;
        for(i = 1; i <= s.size(); i++)
            for(j = i - 1; j >= 0; j--) {
                if(res[j] && dict.find(s.substr(j , i - j)) != dict.end()) {
                    res[i] = true;
                    break;
                }
            }
        return res[s.size()];
    }
};
