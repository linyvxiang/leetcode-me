class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c_flag = 1;
        int cur_pos = digits.size() - 1;
        vector<int> ret;
        while (cur_pos >= 0) {
            int num = digits[cur_pos] + c_flag;
            ret.push_back(num % 10);
            c_flag = num / 10;
            cur_pos--;
        }
        if (c_flag) {
            ret.push_back(1);
        }
        reverse(ret.begin(), ret.end());
        return ret;
   }
};
