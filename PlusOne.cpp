class Solution {
    public:
        vector<int> plusOne(vector<int> &digits) {
            vector<int> ret;
            if(digits.empty())
                return ret;
            int len = digits.size(), flag = 1;
            for(int i = len - 1; i >= 0; i--) {
                ret.push_back((digits[i] + flag) % 10);
                flag = (digits[i] + flag) / 10;
            }
            if(flag)
                ret.push_back(1);
            std::reverse(ret.begin(), ret.end());
            return ret;
        }
};
