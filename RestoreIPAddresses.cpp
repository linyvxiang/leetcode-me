class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        do_generate(0, 0, s, "", res);
        return res;
    }
private:
    void do_generate(int cur_pos, int cur_part_num, string &ori_str,
                        string cur_str, vector<string> &res)
    {
        if(cur_pos == ori_str.size()) {
            if(cur_part_num == 4) {
                cur_str.resize(cur_str.size() - 1);
                res.push_back(cur_str);
            }
            return ;
        }
        if((4 - cur_part_num) * 3 < ori_str.size() - cur_str.size() + cur_part_num)
            return ;
        if((4 - cur_part_num) > ori_str.size() - cur_str.size() + cur_part_num)
            return ;
        int num = 0, i;
        for(i = cur_pos; i < cur_pos + 3; i++) {
            if(i >= ori_str.size())
                break;
            num = num * 10 + ori_str[i] - '0';
            cur_str += ori_str[i];
            if(num <= 255)
                do_generate(i + 1, cur_part_num + 1, ori_str,
                            cur_str + '.', res);
            if(num == 0)
                break;
        }
    }
};
