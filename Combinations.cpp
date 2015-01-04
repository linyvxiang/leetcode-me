class Solution {
    public:
        vector<vector<int> > combine(int n, int k) {
            vector<vector<int> > ret;
            vector<int> cur_subset;
            if(n < k)
                return ret;
            generate_subsets(1, n, k, cur_subset, ret);
            return ret;
        }
    private:
        void generate_subsets(int cur_pos, int n, int k,
                                vector<int> &cur_subset,
                               vector<vector<int> > &ret) 
        {
            if(cur_subset.size() == k) {
                ret.push_back(cur_subset);
                return ;
            }
            for(int p = cur_pos; p <=n; p++) {
                cur_subset.push_back(p);
                generate_subsets(p + 1, n, k, cur_subset, ret);
                cur_subset.pop_back();
            }
        }
};

