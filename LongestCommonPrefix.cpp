class Solution {
    public:
        string longestCommonPrefix(vector<string> &strs) {
            string ret = "";
            if(strs.empty())
                return ret;
            int cur_pos = 0;
            int flag = false;
            while(1) {
                char cur_ch;
                for(int i = 0; i < strs.size(); i++) {
                    if(cur_pos >= strs[i].size()) {
                        flag = true;
                        break;
                    }
                    if(i == 0) {
                        cur_ch = strs[i][cur_pos];
                        continue;
                    } else if(strs[i][cur_pos] != cur_ch) {
                        flag = true;
                        break;
                    }
                }
                if(flag)
                    break;
                ret += strs[0][cur_pos++];
            }
            return ret;
        }
};
