class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.size() < num2.size()) {
            return multiply(num2, num1);
        }
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        string ret;
        for (int num2_pos = num2.size() - 1; num2_pos >= 0; num2_pos--) {
            string cur_ret;
            int cf = 0;
            for (int num1_pos = num1.size() - 1; num1_pos >= 0; num1_pos--) {
                int t = (num2[num2_pos] - '0') * (num1[num1_pos] - '0') + cf;
                cur_ret += t % 10 + '0';
                cf = t / 10;
            }
            if (cf) {
                cur_ret += cf + '0';
            }
            reverse(cur_ret.begin(), cur_ret.end());
            cur_ret.insert(cur_ret.end(), num2.size() - 1 - num2_pos, '0');
            ret = add_num(ret, cur_ret);
        }
        return ret;
    }
private:
    string add_num(const string& num1, const string& num2) {
        if (num1.empty()) {
            return num2;
        }
        if (num2.empty()) {
            return num1;
        }
        int pos1 = num1.size() - 1;
        int pos2 = num2.size() - 1;
        string ret;
        int cf = 0;
        while (pos1 >= 0 && pos2 >= 0) {
            int t = cf + num1[pos1] - '0' + num2[pos2] - '0';
            ret += t % 10 + '0';
            cf = t / 10;
            pos1--;
            pos2--;
        }
        if (pos1 >= 0) {
            while (pos1 >= 0) {
                int t = cf + num1[pos1] - '0';
                ret += t % 10 + '0';
                cf = t / 10;
                pos1--;
            }
        } else if (pos2 >= 0) {
            while (pos2 >= 0) {
                int t = cf + num2[pos2] - '0';
                ret += t % 10 + '0';
                cf = t / 10;
                pos2--;
            }
        }
        if (cf) {
            ret += cf + '0';
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
