class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if (digits.empty()) {
            return ret;
        }
        map<char, string> alpha_map;
        alpha_map['2'] = "abc";
        alpha_map['3'] = "def";
        alpha_map['4'] = "ghi";
        alpha_map['5'] = "jkl";
        alpha_map['6'] = "mno";
        alpha_map['7'] = "pqrs";
        alpha_map['8'] = "tuv";
        alpha_map['9'] = "wxyz";
        do_generate(alpha_map, digits, 0, "", ret);
        return ret;
    }
private:
    void do_generate(map<char, string>& alpha_map,
                     const string& digits, int cur_pos,
                     string cur_ret, vector<string>& ret) {
        if (cur_pos == digits.size()) {
            ret.push_back(cur_ret);
            return;
        }
        for (int pos = 0; pos < alpha_map[digits[cur_pos]].size(); pos++) {
            do_generate(alpha_map, digits, cur_pos + 1, cur_ret + alpha_map[digits[cur_pos]][pos], ret);
        }
    }
};
