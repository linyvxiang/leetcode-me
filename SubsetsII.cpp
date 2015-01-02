class Solution {
    public:
        vector<vector<int> > subsetsWithDup(vector<int> &S) {
            vector<vector<int> > ret;
            vector<int> cur_res;
            if(S.empty())
                return ret;
            sort(S.begin(), S.end());
            generate_subsets(S, 0, cur_res, ret);
            return ret;
        }
    private:
        void generate_subsets(const vector<int> &s,
                                int cur_pos, vector<int> &cur_res,
                                vector<vector<int> > &ret) 
        {
            ret.push_back(cur_res);

            int p = cur_pos;
            for(; p < s.size(); p++) {
                if(p != cur_pos && s[p] == s[p - 1])
                    continue;
                cur_res.push_back(s[p]);
                generate_subsets(s, p + 1, cur_res, ret);
                cur_res.pop_back();
            }
        }
};
