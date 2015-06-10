class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        do_generate(n, 0, 0, "", ret);
        return ret;
    }
private:
    void do_generate(int n, int left, int right, string cur_ret, vector<string>& ret) {
        if (left == n && right == n) {
            ret.push_back(cur_ret);
            return ;
        }
        if (left < n) {
            do_generate(n, left + 1, right, cur_ret + '(', ret);
        }
        if (right < left) {
            do_generate(n, left, right + 1, cur_ret + ')', ret);
        }
    }
};
