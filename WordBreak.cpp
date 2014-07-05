class Solution {
public:
    bool wordBreak(string s, vector<string> &dict) {
        bool res_table[s.size()];
        int i;
        res_table[0] = false;
        for(i = 0; i < s.size(); i++) {
            int j = 0;
            res_table[i] = false;
            for(j = 0; j < dict.size(); j++) {
                if(check(res_table, i, s, dict[j])) {
                    res_table[i] = true;
                    break;
                }
            }
        }
        for(i = 0; i < s.size(); i++)
            printf("%d\n", res_table[i]);
        return res_table[s.size() - 1];
    }
private:
    bool check(bool table[], int cur_pos, const string &s, const string &tmp)
    {
        int t = cur_pos - tmp.size();
        if(t < -1)
            return false;
        if(t > -1 && table[cur_pos - tmp.size()] == false)
            return false;
        int i;
        for(i = 0; i < tmp.size(); i++)
            if(s[cur_pos - tmp.size() + 1 + i] != tmp[i])
                return false;
        return true;
    }
};
