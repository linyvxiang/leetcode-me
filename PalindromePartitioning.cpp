class Solution {
public:
    vector<vector<string> > partition(string s) {
        vector<vector<string> > res;
        vector<vector<string> > prev;
        vector<string> tp;
        string ss;
        ss += s[0];
        tp.push_back(ss);
        prev.push_back(tp);
        int i, j, k, start;
        for(i = 1; i < s.size(); i++) {
            for(j = 0; j < prev.size(); j++) {
                for(k = 0; k < prev[j].size(); k++) {
                    string t = "";
                    for(start = k; start < prev[j].size(); start++) {
                        t += prev[j][start];
                    }
                    t += s[i];
                    int m;
                    vector<string> next;
                    if(check(t)) {
                        for(m = 0; m < k; m++) {
                            next.push_back(prev[j][m]);
                        }
                        next.push_back(t);
                        res.push_back(next);
                    }
            }
                vector<string> tt = prev[j];
                string ttt = "";
                ttt += s[i];
                tt.push_back(ttt);
                res.push_back(tt);
            }
       
            prev = res;
            res.clear();
        }
        return prev;
    }
private:
    bool check(string s)
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
