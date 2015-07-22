class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur_ret;
        vector<vector<int>> ret;
        do_combine(1, k, n, cur_ret, ret);
        return ret;
    }
private:
    void do_combine(int cur_num, int k, int n,
                    vector<int>& cur_ret,
                    vector<vector<int>>& ret) {
        if (cur_ret.size() == k) {
            ret.push_back(cur_ret);
            return;
        }
        for (int num = cur_num; num <= n; num++) {
            cur_ret.push_back(num);
            do_combine(num + 1, k, n, cur_ret, ret);
            cur_ret.pop_back();
        }
    }
};
