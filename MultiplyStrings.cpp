class Solution {
public:
    string multiply(string num1, string num2) {
        string res = "";
        if(num1 == "0" || num2 == "0")
            return "0";
        if(num2.size() > num1.size())
            return multiply(num2, num1);
        int index_num1, index_num2 = num2.size() - 1;
        while(index_num2 >= 0) {
            string tmp_res = get_mid_str(num1, num2, index_num2);

            add_str(res, tmp_res, num2.size() - 1 - index_num2);

            index_num2--;
        }
        return res;
    }
private:
    string get_mid_str(string &num1, string &num2, int index_num2)
    {
        string tmp = "";
        int index_num1 = num1.size() - 1, flag = 0;
        while(index_num1 >= 0) {
            int cur_pos = (num1[index_num1] - '0') * (num2[index_num2] - '0')
                            + flag;
            flag = cur_pos / 10;
            tmp.insert(0, 1, cur_pos % 10 + '0');
            index_num1--;
        }
        if(flag)
            tmp.insert(0, 1, flag + '0');
        return tmp;
    }
    void add_str(string &res, string &tmp_res, int index)
    {
        if(res == "") {
            res = tmp_res;
            return ;
        }
        int index1 = res.size() - index - 1, index2 = tmp_res.size() - 1, flag = 0;
        while(index1 >= 0 && index2 >= 0) {
            int t = (res[index1] - '0' + tmp_res[index2] - '0');
            res[index1] = (t + flag) % 10 + '0';
            flag = (t + flag) / 10;
            index1--;
            index2--;
        }
        while(index2 >=0) {
            int t = (flag + tmp_res[index2] - '0');
            res.insert(0, 1, t % 10 + '0');
            flag = t / 10;
            index2--;
        }
        if(flag)
            res.insert(0, 1, flag + '0');
    }
};
