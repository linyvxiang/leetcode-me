class Solution {
public:
    int numDistinct(string s, string t) {
        if (s.size() < t.size()) {
            return 0;
        }
        vector<vector<int> > num(t.size(), vector<int>(s.size(), 0));
        for (int i = 0; i < t.size(); i++) {
            for (int j = 0; j < s.size(); j++) {
                if (s[j] == t[i]) {
                    if (i == 0 && j == 0) {
                        num[i][j] = 1;
                    } else if (i > 0 && j > 0){
                        num[i][j] = num[i - 1][j - 1] + num[i][j - 1];
                    } else if (i == 0) {
                        num[i][j] = num[i][j - 1] + 1;
                    }
                } else {
                    num[i][j] = num[i][j - 1];
                }
            }
        }
        return num[t.size() - 1][s.size() - 1];
    }
};
