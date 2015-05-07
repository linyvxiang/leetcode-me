class Solution {
public:
    vector<vector<string> > partition(string s) {
        vector<vector<string> > ret;
        vector<string> cur_ret;
        do_partition(s, "", 0, cur_ret, ret);
        return ret;
    }
private:
    bool check(const string& str) {
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
    void do_partition(const string& s, string cur_str, int pos,
                        vector<string>& cur_ret,
                        vector<vector<string> >& ret) {
        if (pos == s.size()) {
            if (cur_str == "") {
                ret.push_back(cur_ret);
            }
            return ;
        }
        for (int p = pos; p < s.size(); p++) {
            cur_str += s[p];
            if (check(cur_str)) {
                cur_ret.push_back(cur_str);
                do_partition(s, "", p + 1, cur_ret, ret);
                cur_ret.pop_back();
            }
        }
    }
};