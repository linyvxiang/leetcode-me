class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ret;
        vector<int> cur_ret;
        if (k > n) {
            return ret;
        }
        generate_combines(n, 1, k, cur_ret, ret);
        return ret;
    }
private:
    void generate_combines(int n, int cur_pos, int k,
                            vector<int>& cur_ret, 
                            vector<vector<int> >& ret) {
        if (cur_ret.size() == k) {
            ret.push_back(cur_ret);
            return;
        }
        if (cur_pos == n + 1) {
            return;
        }
        cur_ret.push_back(cur_pos);
        generate_combines(n, cur_pos + 1, k, cur_ret, ret);
        cur_ret.pop_back();
        generate_combines(n, cur_pos + 1, k, cur_ret, ret);
    }
};
