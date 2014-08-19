class Solution {
public:
    vector<string> dic{" ", " ", "abc", "def", "ghi", "jkl",
                        "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        do_generate_combinations(0, "", digits, res);
        return res;
    }
private:
    void do_generate_combinations(int cur_pos, string cur_str,
                                    string &ori_str, vector<string> &res)
    {
        if(cur_pos == ori_str.size()) {
            res.push_back(cur_str);
            return ;
        }
        int i;
        for(i = 0; i < dic[ori_str[cur_pos] - '0'].size(); i++)
            do_generate_combinations(cur_pos + 1, cur_str + dic[ori_str[cur_pos] - '0'][i],
                                        ori_str, res);
    }
};
