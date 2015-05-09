class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        if (beginWord == endWord) {
            return 0;
        }
        return check_trans(beginWord, endWord, wordDict);
    }
private:
    bool check(const string& str, const string& endWord) {
        int count = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] != endWord[i]) {
                count++;
            }
            if (count > 1) {
                break;
            }
        }
        return count == 1;
    }
    int check_trans(string& beginWord, string& endWord,
            unordered_set<string>& wordDict) {
        queue<string> Q;
        Q.push(beginWord);
        wordDict.erase(beginWord);
        wordDict.erase(endWord);
        int cur_level = 1;
        int next_level = 0;
        int level_num = 0;
        map<string, bool> used;
        while (!Q.empty()) {
            string cur_str = Q.front();
            Q.pop();
            cur_level--;
            if (check(cur_str, endWord)) {
                return level_num + 2;
            }
            for (int i = 0; i < cur_str.size(); i++) {
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (cur_str[i] != ch) {
                        string new_str = cur_str;
                        new_str[i] = ch;
                        if (wordDict.find(new_str) != wordDict.end()
                                && used.find(new_str) == used.end()) {
                            used[new_str] = true;
                            next_level++;
                            Q.push(new_str);
                        }
                    }
                }
            }
            if (cur_level == 0) {
                cur_level = next_level;
                next_level = 0;
                level_num++;
            }
        }
        return 0;
    }
};
