class Solution {
public:
    string countAndSay(int n) {
        int cur_n = 1;
        string cur_str = "11";
        while(cur_n < n) {
            string tmp = "";
            int cur_p = 0, next_p = 0;
            while(cur_p < cur_str.size()) {
                next_p = cur_p;
                while(next_p < cur_str.size() &&
                        cur_str[next_p] == cur_str[cur_p])
                    next_p++;
                tmp += next_p - cur_p + '0';
                tmp += cur_str[cur_p];
                cur_p = next_p;
            }
            cur_str = tmp;
            cur_n++;
        }
        return cur_str;
    }
};
