class Solution {
public:
    string countAndSay(int n) {
        char ch = '1';
        string cur_ret;
        cur_ret += ch;
        string next_ret;
        for (int i = 1; i < n; i++) {
            int fast = 0;
            int slow = 0;
            while (fast < cur_ret.size()) {
                while (fast < cur_ret.size() && cur_ret[fast] == cur_ret[slow]) {
                    fast++;
                }
                next_ret += fast - slow + '0';
                next_ret += cur_ret[slow];
                slow = fast;
            }
            cur_ret = next_ret;
            next_ret = "";
        }
        return cur_ret;
    }
};
