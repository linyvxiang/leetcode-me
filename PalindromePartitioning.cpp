class Solution {
public:
    vector<vector<string> > partition(string s) {
        vector<vector<string> > res;
        if(s.size() == 0)
            return res;
        vector<string> tmp_res;
        do_partition(s, 0, res, tmp_res);
        return res;
    }
private:
    void do_partition(string &s, int cur_pos,
                        vector<vector<string> >  &res, vector<string> &tmp_res)
    {
        if(cur_pos == s.size()) {
            if(!tmp_res.empty())
                res.push_back(tmp_res);
            return ;
        }
        int start;
        string cur = "";
        for(start = cur_pos; start < s.size(); start++) {
            cur += s[start];
            if(check(cur)) {
                tmp_res.push_back(cur);
                do_partition(s, start + 1, res, tmp_res);
                tmp_res.pop_back();
            }
        }
    }
    bool check(string &str)
    {
        int start = 0, end = str.size() - 1;
        while(start <= end) {
            if(str[start++] != str[end--])
                return false;
        }
        return true;
    }
};
