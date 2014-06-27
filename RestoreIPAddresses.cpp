class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if(s.size() == 0)
            return res;
        do_generate_ip_address(0, 0, s, "", res);
        return res;
    }
private:
    void do_generate_ip_address(int cur_steps, int cur_pos, string target_str,
                                        string cur_str, vector<string> &res)
    {
        if(cur_steps == 4 && cur_pos == target_str.size()) {
            cur_str.resize(cur_str.size() - 1);
            res.push_back(cur_str);
            return ;
        }
        
        if(target_str.size() - cur_pos < 4 - cur_steps)
            return ;
        if(target_str.size() - cur_pos > 3 * (4 - cur_steps))
            return ;

        int num = 0, i;
        for(i = cur_pos; i < cur_pos + 3; i++) {
            if(i >= target_str.size())
                break;
            cur_str += target_str[i];
            num = num * 10 + target_str[i] - '0';
            if(num <= 255)
                do_generate_ip_address(cur_steps + 1, i + 1, target_str,
                                                    cur_str + '.', res);

            if(num == 0)
                break;
        }
    }
};
