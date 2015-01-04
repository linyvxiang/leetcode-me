class Solution {
    public:
        vector<vector<int> > subsets(vector<int> &S) {
            vector<vector<int> > ret;
            vector<int> cur_subset;
            if(S.empty())
                return ret;
            sort(S.begin(), S.end());
            generate_subsets(0, S, cur_subset, ret);
            return ret;
        }
    private:
        void generate_subsets(int cur_pos,
                                const vector<int> &S,
                                vector<int> &cur_subset,
                                vector<vector<int> > &ret)
        {
            ret.push_back(cur_subset);
            int p;
            for(p = cur_pos; p < S.size(); p++) {
                cur_subset.push_back(S[p]);
                generate_subsets(p + 1, S, cur_subset, ret);
                cur_subset.pop_back();
            }
       }
};
