class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        if (beginWord == endWord) {
            return 0;
        }
        return calc_steps(beginWord, endWord, wordDict);
    }
private:
    int calc_steps(const string& begin_word, const string& end_word,
            const unordered_set<string>& dict) {
        queue<string> Q;
        Q.push(begin_word);
        int level_num = 1;
        int cur_num = 1;
        int next_num = 0;
        unordered_set<string> used;
        used.insert(begin_word);
        while (!Q.empty()) {
            string cur_word = Q.front();
            Q.pop();
            if (cur_word == end_word) {
                return level_num;
            }
            cur_num--;
            for (int i = 0; i < cur_word.size(); i++) {
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (ch == cur_word[i]) {
                        continue;
                    } else {
                        string tmp_word = cur_word;
                        tmp_word[i] = ch;
                        if (used.find(tmp_word) == used.end() &&
                                dict.find(tmp_word) != dict.end()) {
                            used.insert(tmp_word);
                            Q.push(tmp_word);
                            next_num++;
                        }
                    }
                }
            }
            if (cur_num == 0) {
                swap(cur_num, next_num);
                level_num++;
            }
        }
        return 0;
    }
};
