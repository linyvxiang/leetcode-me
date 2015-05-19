class Solution {
public:
    string addBinary(string a, string b) {
        int pos_a = a.size() - 1;
        int pos_b = b.size() - 1;
        string ret;
        int c_flag = 0;
        while (pos_a >= 0 && pos_b >= 0) {
            ret += (a[pos_a] - '0' + b[pos_b] - '0' + c_flag) % 2 + '0';
            c_flag = (a[pos_a] - '0' + b[pos_b] - '0' + c_flag) / 2;
            pos_a--;
            pos_b--;
        }
        if (pos_a >= 0) {
            while (pos_a >= 0) {
                ret += (a[pos_a] - '0' + c_flag) % 2 + '0';
                c_flag = (a[pos_a] - '0' + c_flag) / 2;
                pos_a--;
            }
        }
        if (pos_b >= 0) {
            while (pos_b >= 0) {
                ret += (b[pos_b] - '0' + c_flag) % 2 + '0';
                c_flag = (b[pos_b] - '0' + c_flag) / 2;
                pos_b--;
            }
        }
        if (c_flag) {
            ret += '1';
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
