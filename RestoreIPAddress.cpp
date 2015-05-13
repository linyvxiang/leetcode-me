class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        restore_ip(s, "", 0, 0, ret);
        return ret;
    }
private:
    void restore_ip(const string& s, string ip_str,
                    int cur_pos, int part_num,
                    vector<string>& ret) {
        if (part_num == 4) {
            if (cur_pos == s.size()) {
                ip_str.resize(ip_str.size() - 1);
                ret.push_back(ip_str);
            }
            return ;
        }
        if (s.size() - cur_pos < 4 - part_num) {
            return ;
        }
        if (s.size() - cur_pos > (4 - part_num) * 3) {
            return ;
        }
        int pos = cur_pos;
        int cur_num = 0;
        for (; pos < cur_pos + 3; pos++) {
            cur_num = cur_num * 10 + s[pos] - '0';
            ip_str += s[pos];
            if (cur_num == 0) {
                restore_ip(s, ip_str + ".", pos + 1, part_num + 1, ret);
                break;
            }
            if (cur_num > 255) {
                break;
            }
            restore_ip(s, ip_str + ".", pos + 1, part_num + 1, ret);
        }
    }
};
