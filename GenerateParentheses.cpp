class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string cur_str = "";
        do_generate(0, 0, n, cur_str, ret);
        return ret;
    }
private:
    void do_generate(int left, int right, int n,
            string cur_str, vector<string>& ret) {
        if (left == n && right == n) {
            ret.push_back(cur_str);
            return;
        }
        if (left < n) {
            do_generate(left + 1, right, n, cur_str + '(', ret);
        }
        if (right < left) {
            do_generate(left, right + 1, n, cur_str + ')', ret);
        }
    }
};
