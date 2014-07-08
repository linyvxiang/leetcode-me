class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        bool flag[num.size()];
        memset(flag, false, sizeof(flag));

        vector<int> cur_res;
        vector<vector<int> > fin_res;
        do_generate(flag, num, cur_res, fin_res);
        return fin_res;
    }
private:
    void do_generate(bool flag[], vector<int> &num, vector<int> &cur_res, vector<vector<int> > &fin_res)
    {
        if(cur_res.size() == num.size()) {
            fin_res.push_back(cur_res);
            return ;
        }

        int i;
        for(i = 0; i < num.size(); i++) {
            if(!flag[i]) {
                flag[i] = true;
                cur_res.push_back(num[i]);
                do_generate(flag, num, cur_res, fin_res);
                cur_res.pop_back();
                flag[i] = false;
            }
        }
    }
};
