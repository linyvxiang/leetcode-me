class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int str_nums = strs.size(), i, cur_len = 0;
        string cur_str = "";
        if(strs.empty())
            return cur_str;
        while(1) {
            if(cur_len >= strs[0].size())
                return move(cur_str);
            for(i = 1; i < str_nums; i++) {
                if(cur_len >= strs[i].size())
                    return move(cur_str);
                if(strs[i][cur_len] != strs[0][cur_len])
                    return move(cur_str);
            }
            cur_str += strs[0][cur_len];
            cur_len++;
        }
    }
};
