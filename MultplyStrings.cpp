class Solution {
    public:
        string multiply(string num1, string num2) {
            if(num1 == "0" || num2 == "0")
                return "0";
            string ret = "";
            reverse(num1.begin(), num1.end());
            reverse(num2.begin(), num2.end());
            for(int i = 0; i < num2.size(); i++) {
                string tmp = do_multiply(num1, num2[i]);
                tmp.insert(tmp.begin(), i, '0');
                ret = add_str(tmp, ret);
            }
            reverse(ret.begin(), ret.end());
            return ret;
        }
    private:
        string add_str(const string &str1, const string &str2)
        {
            string r = "";
            int i = 0, j = 0, flag = 0;
            while(i < str1.size() && j < str2.size()) {
                int t = (str1[i++] - '0' + str2[j++] - '0' + flag);
                r += t % 10 + '0';
                flag = t / 10;
            }
            if(i < str1.size()) {
                while(i < str1.size()) {
                    int t = str1[i++] - '0' + flag;
                    r += t % 10 + '0';
                    flag = t / 10;
                }
            } else {
                while(j < str2.size()) {
                    int t = str2[j++] - '0' + flag;
                    r += t % 10 + '0';
                    flag = t / 10;
                }
            }
            if(flag)
                r += flag + '0';
            return r;
        }
        string do_multiply(const string &num1, char ch)
        {
            string r = "";
            int flag = 0;
            for(int i = 0; i < num1.size(); i++) {
                int t = (num1[i] - '0') * (ch - '0') + flag;
                r += (t % 10 + '0');
                flag = t / 10;
            }
            if(flag)
                r += flag + '0';
            return r;
        }
};
