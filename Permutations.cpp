class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > ret;
        vector<int> cur_ret;
        if(num.empty())
            return ret;
        vector<bool> flag(num.size(), false);
        sort(num.begin(), num.end());
        do_generate(num, 0, flag, cur_ret, ret);
        return ret;
    }
private:
    void do_generate(const vector<int> &num, int cur_size, vector<bool> &flag,
                    vector<int> &cur_ret, vector<vector<int> > &ret)
    {
        if(cur_size == num.size()) {
            ret.push_back(cur_ret);
            return ;
        }
        for(int i = 0; i < num.size(); i++) {
            if(!flag[i]) {
                flag[i] = true;
                cur_ret.push_back(num[i]);
                do_generate(num, cur_size + 1, flag, cur_ret, ret);
                cur_ret.pop_back();
                flag[i] = false;
            }
        }
    }
};
