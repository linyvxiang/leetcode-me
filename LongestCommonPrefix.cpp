class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret;
        if (strs.empty()) {
            return ret;
        }
        for (int cur_pos = 0; cur_pos < strs[0].size(); cur_pos++) {
            for (int i = 1; i < strs.size(); i++) {
                if (strs[i].size() <= cur_pos || strs[i][cur_pos] != strs[0][cur_pos]) {
                    return ret;
                }
            }
            ret += strs[0][cur_pos];
        }
        return ret;
    }
};
