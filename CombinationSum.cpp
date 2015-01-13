class Solution {
    public:
        vector<vector<int> > combinationSum(vector<int> &num, int target) {
            vector<vector<int> > ret;
            vector<int> cur_ret;
            if(num.empty())
                return ret;
            sort(num.begin(), num.end());
            do_generate(num, target, 0, 0, cur_ret, ret);
            return ret;
        }
    private:
        void do_generate(const vector<int> &num, int target, int cur_sum,
                            int cur_pos, vector<int> &cur_ret, vector<vector<int> > &ret)
        {
            if(cur_sum > target)
                return ;
            if(cur_sum == target)
                ret.push_back(cur_ret);
            int p = cur_pos; 
            while(p < num.size()) {
                cur_ret.push_back(num[p]);
                do_generate(num, target, cur_sum + num[p], p, cur_ret, ret);
                cur_ret.pop_back();
                p++;
                while(p < num.size() && num[p] == num[p - 1])
                    p++;
            }
        }
};
