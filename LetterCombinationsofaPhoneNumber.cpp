class Solution {
public:
    vector<string> keyboard { " ", "", "abc", "def",
                                "ghi", "jkl", "mno", "qprs", "tuv", "wxyz"};                                   
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        generate(digits, 0, "", res);       
        return res;
    }
private:
    void generate(string &digits, int cur_pos, string tmp, vector<string> &res)
    {
        if(cur_pos == digits.size()) {
            res.push_back(tmp);
            return ;
        }
        for(auto c : keyboard[digits[cur_pos] - '0'])
            generate(digits, cur_pos + 1, tmp + c, res);
    }
};
