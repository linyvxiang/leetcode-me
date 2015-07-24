class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        vector<string> cur_ret;
        do_generate(0, "", s, cur_ret, ret);
        return ret;
    }
private:
    bool check(string& str) {
        if (str.empty()) {
            return false;
        }
        int start = 0;
        int end = str.size() - 1;
        while (start <= end) {
            if (str[start++] != str[end--]) {
                return false;
            }
        }
        return true;
    }
    void do_generate(int cur_pos, string cur_str, string& s, 
            vector<string>& cur_ret, vector<vector<string>>& ret) {
        if (cur_pos == s.size()) {
            if (cur_str == "") {
                ret.push_back(cur_ret);
            }
            return;
        }
        for (int pos = cur_pos; pos < s.size(); pos++) {
            cur_str += s[pos];
            if (check(cur_str)) {
                cur_ret.push_back(cur_str);
                do_generate(pos + 1, "", s, cur_ret, ret);
                cur_ret.pop_back();
            }
        }
    }
};
