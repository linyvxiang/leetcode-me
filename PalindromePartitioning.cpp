class Solution {
public:
    vector<vector<string> > partition(string s) {
        vector<vector<string> > res;
        vector<string> cur;
        string str = "";
        do_search(0, str, s, cur, res);
        return res;
    }
private:
    void do_search(int cur_pos, string cur_str, string &s, vector<string> &cur_res,
                                vector<vector<string> > &res)
    {
        if(cur_pos > s.size())
            return ;
        if(cur_pos == s.size()) {
            if(!cur_res.empty()) {
                res.push_back(cur_res);
            }
            return ;
        }
        int start = cur_pos;
        for(; start < s.size(); start++) {
            cur_str += s[start];
            if(check(cur_str)) {
                cur_res.push_back(cur_str);
                do_search(start + 1, "", s, cur_res, res);
                cur_res.pop_back();
            }
        }
    }
    bool check(string &s)
    {
        if(s.size() == 1)
            return true;
        int start = 0, end = s.size() - 1;
        while(start <= end)
            if(s[start++] != s[end--])
                return false;
        return true;
    }
};
