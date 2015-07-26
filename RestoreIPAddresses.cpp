class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        do_restore(0, 0, "", s, ret);
        return ret;
    }
private:
    void do_restore(int cur_pos, int sec_num, string cur_ret,
            string& s, vector<string>& ret) {
        if (cur_pos == s.size()) {
            if (sec_num == 4) {
                cur_ret.resize(cur_ret.size() - 1);
                ret.push_back(cur_ret);
            }
            return;
        }
        if (s.size() - cur_pos < 4 - sec_num ||
                s.size() - cur_pos > 3 * (4 - sec_num)) {
            return;
        }
        string tmp = "";
        for (int pos = cur_pos; pos < cur_pos + 3; pos++) {
            if (tmp == "0") {
                continue;
            }
            tmp += s[pos];
            int cur_num = atoi(tmp.c_str());
            if (0 <= cur_num && cur_num <= 255 &&
                    sec_num < 4) {
                do_restore(pos + 1, sec_num + 1,
                        cur_ret + tmp + '.', s, ret);
            }
        }
    }
};
