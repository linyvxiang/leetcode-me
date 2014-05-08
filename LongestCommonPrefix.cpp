class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string res;
        int i, cur_pos = 0, cur_str = 1;
        if(strs.empty())
            return res;
        if(strs.size() == 1)
            return strs[0];
        bool finish_flag = false;
        while(1) {
            for(cur_str = 1; cur_str < strs.size(); cur_str++) {
                if(cur_pos >= strs[0].size() || strs[cur_str].size() <= cur_pos) {
                    finish_flag = true;
                    break;
                }
                if(strs[cur_str][cur_pos] != strs[0][cur_pos]) {
                    finish_flag = true;
                    break;
                }
            }
            if(finish_flag)
                break;
            res.insert(res.end(), strs[0][cur_pos]);
            cur_pos++;
        }
        return res;
    }
};
