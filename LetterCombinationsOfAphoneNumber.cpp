class Solution {
public:
    vector<string> letterCombinations(string digits) {
        num_map[2] = "abc";
        num_map[3] = "def";
        num_map[4] = "ghi";
        num_map[5] = "jkl";
        num_map[6] = "mno";
        num_map[7] = "pqrs";
        num_map[8] = "tuv";
        num_map[9] = "wxyz";
        vector<string> ret;
        string cur_ret = "";
        do_generate(ret, cur_ret, digits, 0);
        return ret;
    }
private:
    map<int, string> num_map;
    void do_generate(vector<string> &ret, string cur_ret,
            const string &digits, int cur_pos)
    {
        if(cur_pos == digits.size()) {
            ret.push_back(cur_ret);
            return ;
        }
        for(int i = 0; i < num_map[digits[cur_pos] - '0'].size();
                i++)
            do_generate(ret, cur_ret + num_map[digits[cur_pos] - '0'][i],
                                            digits, cur_pos + 1);
    }
};
