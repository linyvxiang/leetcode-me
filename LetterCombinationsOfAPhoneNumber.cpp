class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char, string> alpha_map;
        alpha_map['2'] = "abc";
        alpha_map['3'] = "def";
        alpha_map['4'] = "ghi";
        alpha_map['5'] = "jkl";
        alpha_map['6'] = "mno";
        alpha_map['7'] = "pqrs";
        alpha_map['8'] = "tuv";
        alpha_map['9'] = "wzxy";
        vector<string> ret;
        generate_combinations(digits, alpha_map, "", 0, ret);
        return ret;
    }
private:
    void generate_combinations(const string& digits,
            map<char, string>& alpha_map, string cur_word,
            int depth, vector<string>& ret) {
        if (depth == digits.size()) {
            if (!cur_word.empty()) {
                ret.push_back(cur_word);
            }
            return;
        }

        for (int i = 0; i < alpha_map[digits[depth]].size(); i++) {
            string tmp = cur_word + alpha_map[digits[depth]][i];
            generate_combinations(digits, alpha_map, tmp, depth + 1, ret);
        }
    }
};
